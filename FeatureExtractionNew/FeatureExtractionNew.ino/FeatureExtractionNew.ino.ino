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
    static unsigned int splitPos = 0;
    static boolean caching = false;
    char next = Serial.read();
    if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_' || next == '1') {
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
      ExtractionHandler handler;
      ExtractionDelegate::doCache = caching;
      vector<double> values = Data::values_thousand;
      std::map<string, double> params = {{"mean_n_abs_max_n", 8}, {"change_quantile_lower", -0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0}, {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1}, {"mfcc_sampling_rate", 100}, {"mfcc_num_filter", 48}, 
          {"mfcc_m", 1}, {"lpc_auto_n", values.size()}, {"lpc_n", values.size()}, {"lpcc_auto_n", values.size()}, {"lpcc_n", values.size()}, {"lpcc_cep_length", values.size()}};
      long dur;
      Serial.print(F("Starting feature extraction, Caching = "));
      Serial.println(ExtractionDelegate::doCache);
      long timer;
      if(strcmp(input, "all") == 0){
         timer = millis();
         std::map<string, double> results = delegate.extractAll(values, params);
         dur = millis() - timer;
         Serial.print(F("Extract all has finished, took "));
         Serial.print(dur);
         Serial.println(F(" ms"));
         
      } else if (strcmp(input, "all_iterative") == 0){
        std::map<string, double> results;
        for (auto iter : delegate.handlers) {
          timer = millis();
          double res = (handler.*(iter.second))(iter.first, values);
          dur = millis() - timer;
          results.emplace(iter.first, res);
          printTime(iter.first, res, dur);
        }
        
        for (string feature : ExtractionDelegate::parameterFeatures){
          timer = millis();
          double res = delegate.extractOne(feature, values, params);
          dur = millis() - timer;
          results.emplace(feature, res);
          printTime(feature, res, dur);
        }
      
      } else if (strcmp(input, "fft") == 0){
          timer = millis();
          vector<cd> spectrum = delegate.extractSpectrum(values);
          dur = millis() - timer;
          printTime(input, spectrum[0].real, dur);
      
      } else if (strcmp(input, "mfcc") == 0 || strcmp(input, "lpc") == 0 || strcmp(input, "lpcc") == 0) {
          timer = millis();
          vector<double> coeffs = delegate.extractOneVectorial(input, values, params);
          dur = millis() - timer;
          printTime(input, coeffs[0], dur);
          
      } else {
          timer = millis();
          double res = delegate.extractOne(input, values, params);
          dur = millis() - timer;
          printTime(input, res, dur);
      }
      
      ExtractionDelegate::calculated.clear();
      Serial.println(F("Close session\n")); 
      delay(100);
      input[pos] = '\0';
      pos = 0;
    }
  }
}

void printTime(string feature, double res, long dur){
  Serial.print(feature.c_str());
  Serial.print(F(": "));
  Serial.print(res, 7);
  Serial.print(F(", took "));
  Serial.print(dur);
  Serial.println(F(" ms"));
}