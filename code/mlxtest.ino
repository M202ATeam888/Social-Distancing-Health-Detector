

#include <Wire.h>
#include "Adafruit_MLX90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define TrigPin A3
#define EchoPin A2
#define bb 13
float Value_cm;
int t1;
void setup()
{
  Serial.begin(9600);

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(bb, OUTPUT);
  digitalWrite(bb, 1);
  delay(300);
  digitalWrite(bb, 0);
  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
}

void loop() {

  
  digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  Value_cm = float( pulseIn(EchoPin, HIGH) * 17 )/1000; //将回波时间换算成cm

  Serial.print(Value_cm);
  Serial.println("cm");
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  t1=mlx.readObjectTempC();
  Serial.print("*C\tObject = "); Serial.print(t1); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  if(Value_cm<150)
  {
      digitalWrite(bb, HIGH);
      delay(300);
      digitalWrite(bb, 0); 
  }
  else if( t1>33)
  {
      digitalWrite(bb, HIGH);
      delay(100);
      digitalWrite(bb, 0);  
  }  
  else
  {
     digitalWrite(bb, 0);    
  }
  delay(100);
  
}
