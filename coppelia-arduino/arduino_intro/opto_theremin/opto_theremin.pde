/**
 @brief Opto thermin, is a sine audio signal modulated in freccuency by a LDR as an optical sensor.
*/

#include <Tone.h>

#define LIGHT_CONTROL_PIN  11
#define POT_PIN  0
#define LDR_PIN  1
#define SPEAKER_PIN  6
#define MAX_PITCH  2000
#define MIN_PITCH  50

#define LDR_MAX  380
#define LDR_MIN  10

Tone theremin;

void setup(){
  Serial.begin(9600);
  theremin.begin( SPEAKER_PIN );
  pinMode( 11, OUTPUT );
  pinMode( LIGHT_CONTROL_PIN, OUTPUT );
                                                  // [0, 1023]
  analogWrite( LIGHT_CONTROL_PIN, 255 );     // [0, 255]

  theremin.play( 440 );
  delay(1000);
  theremin.stop(); 
}

int v_pot = 0;
unsigned long volume = 0;
unsigned long pitch = 0;

int ldr_min = LDR_MIN;

void loop() {
  
  pitch = analogRead( LDR_PIN );
//  Serial.print( "pitch = " ); Serial.println( pitch );

  int A = (MAX_PITCH - MIN_PITCH);
  A = A / (LDR_MAX - LDR_MIN);
  int B = MIN_PITCH * LDR_MAX;
  B = B - (MAX_PITCH - LDR_MIN);
  B = B / (LDR_MAX - LDR_MIN);
  
  pitch = A * pitch;
  pitch = pitch - B;

  theremin.play( pitch );

//  Serial.print( "pitch = " ); Serial.println( pitch );

}
