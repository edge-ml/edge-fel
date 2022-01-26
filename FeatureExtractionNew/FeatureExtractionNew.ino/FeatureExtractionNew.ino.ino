#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "Data.h"
#include "mbed.h" 
#include "Cmplx.h"
#include <vector>
#include <iostream>

using namespace eh;
using namespace ed;
using namespace std;
using namespace ex;
using namespace co;

void print_memory_info() {
    // allocate enough room for every thread's stack statistics
    int cnt = osThreadGetCount();
    mbed_stats_stack_t *stats = (mbed_stats_stack_t*) malloc(cnt * sizeof(mbed_stats_stack_t));
 
    cnt = mbed_stats_stack_get_each(stats, cnt);
    for (int i = 0; i < cnt; i++) {
        printf("Thread: 0x%lX, Stack size: %lu / %lu\r\n", stats[i].thread_id, stats[i].max_size, stats[i].reserved_size);
    }
    free(stats);
 
    // Grab the heap statistics
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    printf("Heap size: %lu / %lu bytes\r\n", heap_stats.current_size, heap_stats.reserved_size);
}

void setup() {
  Serial.begin(115200);
  delay(100);
}

void loop() {
  static char input[22];
  ExtractionHandler handler;
  while (Serial.available() > 0){
    static unsigned int pos = 0;
    char next = Serial.read();
    /*Serial.println(next);
    delay(10);*/
    if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_') {
      input[pos] = next;
      pos++;
    } else if (pos == 0){
      continue;
      
    } else {
      ExtractionDelegate delegate;
      ExtractionDelegate::doCache = true;
      std::map<string, double> params = { {"mean_n_abs_max_n", 8}, {"change_quantile_lower", -0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0}, {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1} };
      long dur;
      Serial.print(F("Starting feature extraction, Caching = "));
      Serial.println(ExtractionDelegate::doCache);
     
      if(input[0] == 'a' && input[1] == 'l' && input[2] == 'l'){
         vector<double> values = Data::values_thousand;
         long timer = millis();
         std::map<string, double> results;
         print_memory_info();
         for (auto iter : delegate.handlers) {
            double value = (handler.*(iter.second))(iter.first, values);
            results.emplace(iter.first, value);
         }
         print_memory_info(); 
         for (string feature : ExtractionDelegate::parameterFeatures){
            double value = delegate.extractOne(feature, values, params);
            results.emplace(feature, value);
         }
         print_memory_info();
         //std::map<string, double> results = delegate.extractAll(values, params);
         dur = millis() - timer;
         /*for (auto single : results) {
            Serial.print(single.first.c_str());
            Serial.print(": ");
            Serial.println(single.second, 7);
            delay(10);
         }*/
      } else {
         vector<double> values = Data::values_thousand;
         long timer = millis();
         double result = delegate.extractOne(input, values, params);
         dur = millis() - timer;
         Serial.print(input);
         Serial.print(F(": "));
         Serial.println(result, 7);
        
      }
      Serial.print(F("Feature extraction finished, took "));
      Serial.print(dur);
      Serial.println(F(" ms"));
      ExtractionDelegate::calculated.clear();
      Serial.println(F("Close session\n")); 
      delay(100);
      pos = 0;
    }
  }
}
