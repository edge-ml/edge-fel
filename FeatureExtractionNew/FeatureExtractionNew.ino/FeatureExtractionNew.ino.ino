#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "Data.h"
#include "mbed.h" 
#include "Cmplx.h"
#include <vector>
#include "MemoryInfo.h"

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;
using namespace co;

const unsigned int MAX_INPUT_LENGTH = 25;

void setup() {
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0){
    static char input[MAX_INPUT_LENGTH];
    static unsigned int pos = 0;
    static boolean caching = false;
    char next = Serial.read();
    if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_' || next == '1' || next == ' ') {
      if(next == '1'){
        caching = true;
        continue;
      }
      input[pos] = next;
      pos++;
    } else if (pos == 0){
      continue;
    } else {
      ExtractionDelegate delegate;
      ExtractionDelegate::doCache = caching;
      vector<float>* values = &Data::values_thousand;
      std::map<string, float> params = {{"mean_n_abs_max_n", 8}, {"change_quantile_lower", -0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0}, {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1}, {"mfcc_sampling_rate", 100}, {"mfcc_num_filter", 48}, 
          {"mfcc_m", 1}, {"lpc_auto_n", values->size()}, {"lpc_n", values->size()}, {"lpcc_auto_n", values->size()}, {"lpcc_n", values->size()}, {"lpcc_cep_length", values->size()}};
      long dur;
      Serial.print(F("Starting feature extraction, Caching = "));
      Serial.println(ExtractionDelegate::doCache);
      long timer;
      if(strcmp(input, "all") == 0){
         timer = micros();
         std::map<string, float> results = delegate.extractAll(*values, params);
         dur = micros() - timer;
         Serial.print(F("Extract all has finished, took "));
         Serial.print(dur);
         Serial.println(F(" µs"));

      } else if (strcmp(input, "all_iterative") == 0){
        std::map<string, float> results;
        for (auto iter : delegate.handlers) {
          timer = micros();
          float res = delegate.extractOne(iter.first, *values, params);
          dur = micros() - timer;
          results.emplace(iter.first, res);
          printTime(iter.first, res, dur);
        }
        
        for (string feature : ExtractionDelegate::parameterFeatures){
          timer = micros();
          float res = delegate.extractOne(feature, *values, params);
          dur = micros() - timer;
          results.emplace(feature, res);
          printTime(feature, res, dur);
        }
      
      } else if (strstr(input, "some")){
        char* features = strtok(input, " ");
        features = strtok(NULL, " ");
        std::map<string, float> results;
        while (features){
          timer = micros();
          float res = delegate.extractOne(features, *values, params);
          dur = micros() - timer;
          printTime(features, res, dur);
          results.emplace(features, res);
          features = strtok(NULL, " ");
        }
      
      } else if (strcmp(input, "fft") == 0){
          timer = micros();
          vector<cd> spectrum = delegate.extractSpectrum(*values);
          dur = micros() - timer;
          printTime(input, spectrum[0].real, dur);
      
      } else if (strcmp(input, "mfcc") == 0 || strcmp(input, "lpc") == 0 || strcmp(input, "lpcc") == 0) {
          timer = micros();
          vector<float> coeffs = delegate.extractOneVectorial(input, *values, params);
          dur = micros() - timer;
          printTime(input, coeffs[0], dur);
          
      } else {
          timer = micros();
          float res = delegate.extractOne(input, *values, params);
          dur = micros() - timer;
          printTime(input, res, dur);
      }
      
      ExtractionDelegate::calculated.clear();
      caching = false;
      Serial.println(F("Close session\n")); 
      delay(100);
      input[pos] = '\0';
      pos = 0;
    }
  }
}

void printTime(string feature, float res, long dur){
  Serial.print(feature.c_str());
  Serial.print(F(": "));
  Serial.print(res, 7);
  Serial.print(F(", took "));
  Serial.print(dur);
  Serial.println(F(" µs"));
}
