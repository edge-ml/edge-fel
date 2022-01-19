#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "Data.h"
#include <vector>
#include <iostream>

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;

void setup() {
  Serial.begin(115200);
  delay(10);
}

void loop() {
  boolean start = false;
  unsigned int pos = 0;
  char input[3];
  ExtractionHandler handler;
  while (Serial.available() > 0){
    char next = Serial.read();
    input[pos] = next;
    Serial.println(input[pos]);
    delay(10);
    pos++;
    if((input[0] == 'a') && (input[1] == 'l') && (input[2] == 'l')){
      start = true;
    }
    
    if (start){
      Serial.print(F("Starting feature extraction, Caching = "));
      
      ExtractionDelegate delegate;
      delegate.fillHandlerMap();
      ExtractionDelegate::doCache = true;
      vector<double> values = Data::values_thousand;

      Serial.println(ExtractionDelegate::doCache);

      std::map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };

      
      for (auto iter : ExtractionDelegate::handlers) {
        double value = (handler.*(iter.second))(iter.first, values);
        Serial.println(iter.first.c_str());
        Serial.print(": ");
        Serial.println(value);
        delay(10);
      }
      
      for (string feature : ExtractionDelegate::parameterFeatures){
        double res = delegate.extractOne(feature, values, params);
        Serial.print(feature.c_str());
        Serial.print(": ");
        Serial.println(res);
      }
/*
      std::map<string, double> results;
      for (auto iter : ExtractionDelegate::handlers) {
        double value = (handler.*(iter.second))(iter.first, values);
        Serial.println(iter.first.c_str());
        Serial.print(": ");
        Serial.println(value);
        results.emplace(iter.first, value);
      }
      std::map<string, double> parameterFeatures = delegate.extractSome(ExtractionDelegate::parameterFeatures, values, params);
      results.insert(parameterFeatures.begin(), parameterFeatures.end());*/

      /*
      long timer = millis();
      std::map<string, double> results = delegate.extractAll(values, params);
      long dur = millis() - timer;
      
      for (auto single : results) {
        Serial.print(single.first.c_str());
        Serial.print(": ");
        Serial.println(single.second);
        delay(10);
      }

      Serial.print(F("Feature extraction finished, took "));
      Serial.print(dur);
      Serial.println(F(" ms"));
      
      */
      //Clear Cache
      ExtractionDelegate::calculated.clear();
      
      //Clear Serial input
      while (Serial.available() > 0){
          Serial.read();
      }
      delay(10);
    }
  }
    
}
