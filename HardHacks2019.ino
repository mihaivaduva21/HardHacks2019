#include "print.h"
#include "statistics.h"

const int trigPin = 8;
const int echoPin = 9;

long prevDistance = 0;
long distance = 0;
long duration = 0;

void setup() {
  Serial.begin( 9600 );
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );
 
}

void loop() {
  
  sendPulse( trigPin );
  duration = pulseIn( echoPin, HIGH ); // milliseconds
  distance = duration * 0.0343 / 2;  // centimeters
  
  registerData( distance );

  if( distance < getMax() ) {
    println( distance  );
    prevDistance = distance;
  }
  else {
    println( getMax() );
  }
  
  delay( 50 );
}

void sendPulse( const int outputPin ) {
  // clear output signal
  digitalWrite( outputPin, LOW );
  delayMicroseconds( 5 );

  // begin signal
  digitalWrite( outputPin, HIGH );
  delayMicroseconds( 10 );
  // end
  digitalWrite( outputPin, LOW );
}


