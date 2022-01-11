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

    String feature = input;
    if (feature == "all"){
      start = true;
    } 
    
    if (start){
      Serial.println("Starting feature extraction");
      
      ExtractionDelegate delegate;
      delegate.fillHandlerMap();
      ExtractionDelegate::doCache = true;
      vector<double> values = Data::values_thousand;

      long timer = millis();
      std::map<string, double> results = delegate.extractAll(values);
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
