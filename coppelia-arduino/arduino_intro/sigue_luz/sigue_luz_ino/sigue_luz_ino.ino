// Sweep
// por BARRAGAN <http://barraganstudio.com> 

#include <Servo.h>

#define LEFT_WHEEL_PIN  9
#define RIGHT_WHEEL_PIN  10
#define LEFT_LDR_PIN  0
#define RIGHT_LDR_PIN  1

Servo left_wheel;  // crea un objeto tipo servo para controlar el servo 
Servo right_wheel;  // crea un objeto tipo servo para controlar el servo 

int left_pos = 90;    // variable para almacenar la posición del servo
int left_pos_read = 0;
int left_vel = 4;
int right_pos = 0;    // variable para almacenar la posición del servo
int right_vel = 1;

int left_ldr = 0;
int right_ldr = 0;
int left_ldr_old = 0;

void setup() 
{ 
  Serial.begin( 9600 );
  Serial.println( "**************** setup *****************" );
  left_wheel.attach( LEFT_WHEEL_PIN );  // liga el servo conectado en el pin 9 al objeto servo
  right_wheel.attach( RIGHT_WHEEL_PIN );  // liga el servo conectado en el pin 9 al objeto servo
  Serial.println( "Putting servo on 90..." );
  left_wheel.write( left_pos );  
  delay( 2000 );
  left_pos_read = left_wheel.read();
  Serial.print( "left_pos_read = " ); Serial.println( left_pos_read );
  Serial.println( "Begining control... . . .   ..   ." );
  left_ldr_old = analogRead( LEFT_LDR_PIN );

} 
int dif_ldr = 0;
float P = 0.1;
void loop() 
{ 
  left_ldr = analogRead( LEFT_LDR_PIN );
  right_ldr = analogRead( RIGHT_LDR_PIN );
  dif_ldr = left_ldr - left_ldr_old;
  
  Serial.print( "left_ldr = " ); Serial.print( left_ldr ); Serial.print( "  left_ldr_old = " ); Serial.print( left_ldr_old ); Serial.print( "  diff = " ); Serial.println( dif_ldr );
  left_ldr_old = left_ldr;

//  left_vel = map( left_vel, -300, 300, -4, 4 );
  if( dif_ldr < 0 ) left_vel = - left_vel;

  left_vel = constrain( left_vel, -1, 1 );

  left_pos += left_vel * abs(dif_ldr) * P;  
  left_pos = constrain( left_pos, 0, 180 );
  Serial.print( "left_vel = " ); Serial.print( left_vel ); Serial.print( "  left_pos = " ); Serial.print( left_pos );   
  left_wheel.write( left_pos );  
/*
  right_wheel.write( right_pos );  
//  left_vel = left_ldr;
  right_vel = -2;
  right_pos += right_vel;

  if( left_pos > 180 ) left_vel = - left_vel;
  if( left_pos <= 0 ) left_vel = - left_vel;
*/  
  delay(15);                       // espera 15 ms para dar tiempo al servo a llegar a la nueva posición 
 // delay(200);                       // 
  left_pos_read = left_wheel.read();
  Serial.print( "  left_pos_read = " ); Serial.println( left_pos_read ); 
  Serial.println();
} 
