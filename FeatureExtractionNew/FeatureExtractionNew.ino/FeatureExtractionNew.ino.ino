#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "mbed.h"
#include "Cmplx.h"
#include <vector>
#include "MemoryInfo.h"

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;
using namespace co;

const unsigned int MAX_INPUT_LENGTH = 100;
const unsigned int START_LENGTH = 25;
const unsigned int PARAM_LENGTH = 1000;

void setup() {
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0) {
    //Start with dataset import preliminary
    static char start[START_LENGTH];
    static unsigned int start_pos = 0;
    char next = Serial.read();

    if (next != '\n' && (next >= 'a' && next <= 'z') || next == ' ') {
      start[start_pos] = next;
      start_pos++;

    } else if (start_pos == 0) {
      //Discard floating bytes in input buffer
      continue;

    } else {
      long dur;
      long timer;

      //Either read end of line or non valid character
      if (strcmp(start, "transfer data of size ")) {
        Serial.println("Start transfer of data");
        timer = micros();
        static long data_size = 0;
        //Read size of dataset
        data_size = Serial.parseInt();
        static vector<float> values;
        values.reserve(data_size);

        //Read values
        while (Serial.available() > 0) {
          //Check for required whitespace before every value
          next = Serial.read();
          if (next == ' ') {
            float value = Serial.parseFloat(SKIP_NONE);
            values.push_back(value);

            //End of line signals end of dataset
          } else if (next == '\n') {
            dur = micros() - timer;
            Serial.print("Data transfer finished, took ");
            Serial.print(dur);
            Serial.println(F(" µs"));

            Serial.println("Start transfer of features");
            timer = micros();
            static char input[MAX_INPUT_LENGTH];
            static char pos = 0;
            static boolean caching = false;
            while (Serial.available() > 0) {
              //Check for requested features
              next = Serial.read();
              if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_' || next == '1' || next == ' ') {
                //Sending a 1 after the features activates caching
                if (next == '1') {
                  caching = true;
                  continue;
                }
                input[pos] = next;
                pos++;

              } else {
                dur = micros() - timer;
                Serial.print("Feature transfer finished, took ");
                Serial.print(dur);
                Serial.println(F(" µs"));

                delay(100);
                
                Serial.println("Start transfer of params");
                timer = micros();
                std::map<string, float> params;
                static char param[PARAM_LENGTH];
                static unsigned int param_pos = 0;
 
                while (Serial.available() > 0) {
                  //Check for params
                  next = Serial.read();
                  if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_' || next == ' ' || next == ':') {
                    if (next == ':') {
                      float param_value = Serial.parseFloat(SKIP_NONE);
                      params.emplace(param, param_value);
                      for (int i = 0; i < param_pos; i++) {
                        param[i] = '\0';
                      }
                      param_pos = 0;
                    } else if (next != ' ') {
                      param[param_pos] = next;
                      param_pos++;
                    }
                  } 
                }
                dur = micros() - timer;
                Serial.print("Param transfer finished, took ");
                Serial.print(dur);
                Serial.println(F(" µs"));
                
                ExtractionDelegate delegate;
                ExtractionDelegate::doCache = caching;
                //long dur;
                Serial.print(F("Starting feature extraction with caching = "));
                Serial.println(ExtractionDelegate::doCache);
                //long timer;
                if (strcmp(input, "all") == 0) {
                  timer = micros();
                  std::map<string, float> results = delegate.extractAll(values, params);
                  dur = micros() - timer;
                  Serial.print(F("Extract all has finished, took "));
                  Serial.print(dur);
                  Serial.println(F(" µs"));

                } else if (strcmp(input, "all_iterative") == 0) {
                  std::map<string, float> results;
                  for (auto iter : delegate.handlers) {
                    timer = micros();
                    float res = delegate.extractOne(iter.first, values, params);
                    dur = micros() - timer;
                    results.emplace(iter.first, res);
                    printTime(iter.first, res, dur);
                  }

                  for (string feature : ExtractionDelegate::parameterFeatures) {
                    timer = micros();
                    float res = delegate.extractOne(feature, values, params);
                    dur = micros() - timer;
                    results.emplace(feature, res);
                    printTime(feature, res, dur);
                  }

                } else if (strstr(input, "some")) {
                  char* features = strtok(input, " ");
                  features = strtok(NULL, " ");
                  std::map<string, float> results;
                  while (features) {
                    timer = micros();
                    float res = delegate.extractOne(features, values, params);
                    dur = micros() - timer;
                    printTime(features, res, dur);
                    results.emplace(features, res);
                    features = strtok(NULL, " ");
                  }

                } else if (strcmp(input, "fft") == 0) {
                  timer = micros();
                  vector<cd> spectrum = delegate.extractSpectrum(values);
                  dur = micros() - timer;
                  printTime(input, spectrum[0].real, dur);

                } else if (strcmp(input, "mfcc") == 0 || strcmp(input, "lpc") == 0 || strcmp(input, "lpcc") == 0) {
                  timer = micros();
                  vector<float> coeffs = delegate.extractOneVectorial(input, values, params);
                  dur = micros() - timer;
                  printTime(input, coeffs[0], dur);

                } else {
                  timer = micros();
                  float res = delegate.extractOne(input, values, params);
                  dur = micros() - timer;
                  printTime(input, res, dur);
                }

                ExtractionDelegate::calculated.clear();
                caching = false;
                Serial.println(F("Close session\n"));
                //Clear input buffer
                for (int i = 0; i < pos; i++) {
                  input[i] = '\0';
                }
                pos = 0;
                //Clear param buffer
                for (int i = 0; i < param_pos; i++) {
                  param[i] = '\0';
                }
                param_pos = 0;
                values.clear();
                params.clear();
              }
            }
          }
          else {
            break;
          }
        }
      }

      for (int i = 0; i < start_pos; i++) {
        start[i] = '\0';
      }
      start_pos = 0;
    }
  }
}

void printTime(string feature, float res, long dur) {
  Serial.print(feature.c_str());
  Serial.print(F(": "));
  Serial.print(res, 7);
  Serial.print(F(", took "));
  Serial.print(dur);
  Serial.println(F(" µs"));
}
