//libreria HX711
#include "HX711.h"

// HX711 circuit wiring
#define DOUT_PIN 2
#define SCK_PIN 3

HX711 celda;

void setup() {
  Serial.begin(9600);
  celda.begin(DOUT_PIN, SCK_PIN);
   if (celda.is_ready()) {
    celda.set_celda();    
    Serial.println("NO COLOCAR NADA SOBRE LA CELDA PARA TARAR");
    delay(5000);
    celda.tare();
    Serial.println("CELDA TARA");
    Serial.print("COLOCAR MASA CONOCIDA");
    delay(2000);
    long reading = celda.read_average(10);
    Serial.print("VALOR A UTILIZAR PARA FACTOR");
    Serial.println(reading);
    delay(5000);
  } 
  else {
    Serial.println(0);
  }
  delay(1000);

}

void loop() {
  Serial.println(celda.read_average(10)); 
}