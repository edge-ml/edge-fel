#include "FEL.h"

void setup() {
  Serial.begin(115200);
  

}

void loop() {
  //Serial.println("ABC");
  //FEL* extractor = new FEL;
  boolean start = false;
  unsigned int pos = 0;
  char input[2];
  while (Serial.available() > 0){
    char next = Serial.read();
    input[pos] = next;
    Serial.write(input[pos]);
    delay(10);
    //Serial.write("start");
    pos++;
  
    if(pos == 2){
      start = true;
      Serial.write("stop");
      break;
    }
  }
  /*
  if(start){
    pos = 0;
    boolean benchmark = false;
    int featureID = input[0];
    if(!input[1] == 0){
      benchmark = true;
    }

    
    int dataSize = 10;
    double data[10] = {0.0, 0.0, 0.1, 0.2, 0.4, 0.5, 0.8, 1.1, 1.6, 2.2};
    long start = 0;
    long duration = 0;
    
    if(benchmark){
      start = millis();
    }
    double res = extractor->extract_one(data, dataSize, featureID);
    
    if(benchmark){
      long finish = millis();
      duration = finish - start;
      Serial.println(duration);
    }
    Serial.println(res);
    start = false;
    
  }*/

  

 
  
}
