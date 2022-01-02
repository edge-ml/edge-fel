void setup() {
  Serial.begin(9600)

}

void loop() {
  boolean start = false;
  while (Serial.available() > 0){
    static char input[3];
    static unsigned int pos = 0;
    char next = Serial.read();

    input[pos] = next;
    pos++;
    if(pos == 3){
      start = true;
    }
  }

  if(start){
    pos = 0;
    int setID = input[0];
    int featureID = input[1];
    int doBenchmark = input[2];

    double[] data = getDataset(setID);
    int dataSize = getDatasize(data);
    Ptr* f = getExtractor(featureID);

    if(benchmark){
      
      double[] results = extractAndGetTime(f, data, dataSize);
      Serial.println(results[0]);
      Serial.println(results[1]);
    } else {
      double res = f(data, dataSize)
      Serial.println(res);
    }
    start = false;
    
  }
