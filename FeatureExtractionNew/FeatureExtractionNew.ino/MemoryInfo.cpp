#include "MemoryInfo.h"

void print_memory_info() {
    // allocate enough room for every thread's stack statistics
    /*int cnt = osThreadGetCount();
    mbed_stats_stack_t *stats = (mbed_stats_stack_t*) malloc(cnt * sizeof(mbed_stats_stack_t));
    cnt = mbed_stats_stack_get_each(stats, cnt);
    for (int i = 0; i < cnt; i++) {
      Serial.print(F("Thread: 0x"));
      Serial.print(stats[i].thread_id);
      Serial.print(F(", Stack size: "));
      Serial.print(stats[i].max_size);
      Serial.print(F(" / "));
      Serial.println(stats[i].reserved_size);
    }
    free(stats);*/
 
    // Grab the heap statistics
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    Serial.print(F("Heap size: "));
    Serial.print(heap_stats.current_size);
    Serial.print(F(" / "));
    Serial.print(heap_stats.reserved_size);
    Serial.println(F(" bytes"));
}
