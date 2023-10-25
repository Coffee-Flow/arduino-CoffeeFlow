#include "DHT.h"

#define dht_type DHT11

const int LM35 = A1;
float temperaturaLM35;

int dht_pin = A0;
DHT dht_1 = DHT(dht_pin, dht_type);

void setup(){
  Serial.begin(9600);
  dht_1.begin();
}

void loop(){
  //coleta de registros
  float umidade = dht_1.readHumidity();
  float temperatura = dht_1.readTemperature();

  //"Manipulação" de registros para simulação
  temperaturaLM35 = ((float(analogRead(LM35))*5/(1023))/0.01) - 6;
  temperatura = temperatura - 5;
  umidade = umidade - 35;

  //
  if(isnan(temperatura) or isnan(umidade)){
    Serial.print("0");
  }else{
    Serial.print(umidade);
    Serial.print(",");
    Serial.print(temperatura);
  }
  Serial.print(",");
  Serial.println(temperaturaLM35);

  delay(1000);
}