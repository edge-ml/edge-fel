#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "Data.h"
#include "mbed.h" 
#include "Cmplx.h"
//#include "mbed_mem_trace.h
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
  delay(10);
  print_memory_info();
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
      print_memory_info();
      ExtractionDelegate delegate;
      ExtractionDelegate::doCache = true;
      print_memory_info();
      vector<double> values = Data::values_thousand;
      print_memory_info();
      Serial.print(F("Starting feature extraction, Caching = "));
      Serial.println(ExtractionDelegate::doCache);

      std::map<string, double> params = { /*{"mean_n_abs_max_n", 8}, {"change_quantile_lower", 0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0}, {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1},*/{"mfcc_sampling_rate", 100}, {"mfcc_num_filter", 48}, {"mfcc_m", 1} };
      print_memory_info();
      vector<double> lpcc = delegate.extractLpcc(values, values.size(), values.size(), values.size());
      Serial.println("Sucess");
      print_memory_info();
      

      /*
      for (auto iter : delegate.handlers) {
        double value = (handler.*(iter.second))(iter.first, values);
        Serial.println(iter.first.c_str());
        Serial.print(F(": "));
        Serial.println(value, 5);
        delay(10);
      }
   
      for (string feature : ExtractionDelegate::parameterFeatures){
        double res = delegate.extractOne(feature, values, params);
        Serial.print(feature.c_str());
        Serial.print(F(": "));
        Serial.println(res, 5);
        delay(10);
      }
      print_memory_info();
      delay(10);
      vector<double> lpc = delegate.extractLpc(values, values.size(), values.size());
      vector<double> lpcc = delegate.extractLpcc(values, values.size(), values.size(), values.size());
      print_memory_info();
      delay(10);*/

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
      
      delay(100);
    }
  }
    
}
