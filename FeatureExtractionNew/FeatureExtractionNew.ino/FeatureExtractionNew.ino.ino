#include "Extractor.h"
#include "ExtractionDelegate.h"
#include "ExtractionHandler.h"
#include "Data.h"
#include "mbed.h" 
#include "Cmplx.h"
#include <vector>

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
      Serial.print("Thread: 0x");
      Serial.print(stats[i].thread_id);
      Serial.print(", Stack size: ");
      Serial.print(stats[i].max_size);
      Serial.print(" / ");
      Serial.println(stats[i].reserved_size);
    }
    free(stats);
 
    // Grab the heap statistics
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    Serial.print(F("Heap size: "));
    Serial.print(heap_stats.current_size);
    Serial.print(F(" / "));
    Serial.print(heap_stats.reserved_size);
    Serial.println(F(" bytes"));
}

void setup() {
  Serial.begin(115200);
  delay(100);
  print_memory_info();
}

void loop() {
  static char input[22];
  static unsigned int pos = 0;
  while (Serial.available() > 0){
    char next = Serial.read();
    if (next != '\n' && (next >= 'a' && next <= 'z') || next == '_') {
      input[pos] = next;
      pos++;
    } else if (pos == 0){
      continue;
    } else {
      ExtractionDelegate delegate;
      ExtractionHandler handler;
      ExtractionDelegate::doCache = true;
      std::map<string, double> params = {{"mean_n_abs_max_n", 8}, {"change_quantile_lower", -0.1}, {"change_quantile_upper", 0.1}, {"change_quantile_aggr", 0}, {"range_count_lower",-1}, 
          {"range_count_upper", 1}, {"count_above_x", 0}, {"count_below_x", 0}, {"quantile_q", 0.5}, {"autocorrelation_lag", 1}};
      long dur;
      Serial.print(F("Starting feature extraction, Caching = "));
      Serial.println(ExtractionDelegate::doCache);
      print_memory_info();
      if(input[0] == 'a' && input[1] == 'l' && input[2] == 'l'){
         vector<double> values = Data::values_thousand;
         print_memory_info();
         for(int i = 0; i < 3; i++){
            values.insert(values.end(), Data::values_thousand.begin(), Data::values_thousand.end());
         }
         print_memory_info();
         long timer = millis();
         std::map<string, double> results = delegate.extractAll(values, params);
         dur = millis() - timer;
         /*for (auto single : results) {
            Serial.print(single.first.c_str());
            Serial.print(F(": "));
            Serial.println(single.second, 7);
         }*/
         print_memory_info();
         
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
      input[pos] = '\0';
      pos = 0;
    }
  }
}
