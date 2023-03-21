//libreria HX711
#include "HX711.h"

//pines celda
#define DOUT_PIN 2
#define SCK_PIN 3

//objeto celda
HX711 celda;
float tara = 74130.00;

void setup() {
  Serial.begin(9600);
  celda.begin(DOUT_PIN, SCK_PIN);
   if (celda.is_ready()) {
    celda.set_scale();    
    // Serial.println("COLOCAR MASA CONOCIDA");
    // delay(10000);
    // long reading = celda.read_average(10);
    // Serial.print("VALOR A UTILIZAR PARA FACTOR");
    // Serial.println(reading);
    // delay(5000);
  } 
  else {
    Serial.println(0);
  }
  delay(1000);

}

void loop() {
  //Se imprime el promedio de los ultimos 10 valores
  long lectura= 16.00*(celda.read_average(5)+tara)/147768.00;
  Serial.println(lectura); 
}
