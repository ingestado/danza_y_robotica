// Sweep
// por BARRAGAN <http://barraganstudio.com> 

#include <Servo.h>

#define LEFT_WHEEL_PIN  10
#define RIGHT_WHEEL_PIN  9
#define LEFT_LDR_PIN  1
#define RIGHT_LDR_PIN  0

Servo left_wheel;  // crea un objeto tipo servo para controlar el servo 
Servo right_wheel;  // crea un objeto tipo servo para controlar el servo 

int left_pos = 0;    // variable para almacenar la posición del servo
int left_vel = 1;
int right_pos = 0;    // variable para almacenar la posición del servo
int right_vel = 0;

void setup() 
{ 
  left_wheel.attach( LEFT_WHEEL_PIN );  // liga el servo conectado en el pin 9 al objeto servo
  right_wheel.attach( RIGHT_WHEEL_PIN );  // liga el servo conectado en el pin 9 al objeto servo
} 

int left_ldr = 0;
int right_ldr = 0;

void loop() 
{ 
  left_ldr = analogRead( LEFT_LDR_PIN );
  right_ldr = analogRead( RIGHT_LDR_PIN );
  
  left_wheel.write( left_pos );  
//  left_vel = left_ldr;
  left_vel = 2;
  left_pos += left_vel;

  right_wheel.write( right_pos );  
//  left_vel = left_ldr;
  right_vel = -2;
  right_pos += right_vel;

  delay(15);                       // espera 15 ms para dar tiempo al servo a llegar a la nueva posición 

} 
