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
      Serial.print("Starting feature extraction, Caching = ");
      
      ExtractionDelegate delegate;
      delegate.fillHandlerMap();
      ExtractionDelegate::doCache = false;
      vector<double> values = Data::values_hundred;

      Serial.println(ExtractionDelegate::doCache);

      std::map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1},  {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };
      
      long timer = millis();
      std::map<string, double> results = delegate.extractAll(values, params);
      long dur = millis() - timer;
      
      for (auto single : results) {
        Serial.print(single.first.c_str());
        Serial.print(": ");
        Serial.println(single.second);
        delay(10);
      }

      Serial.print("Feature extraction finished, took ");
      Serial.print(dur);
      Serial.println(" ms");

      //Clear Serial input
      while (Serial.available() > 0){
          Serial.read();
      }
      delay(10);
    }
  }
    
}
