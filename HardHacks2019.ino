#include "print.h"
#include "statistics.h"

#define SAMPLE_SIZE 5
#define STANDARD_ERROR 1000

int data[ SAMPLE_SIZE ] = { 0 };
double average = 0;
double stanDev = 0;

const int trigPin = 8;
const int echoPin = 9;

long distance = 0;
long duration = 0;

int start = 5;
int end = 25;

void setup() {
  Serial.begin( 9600 );
  BT.begin( 9600 );
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );
 
}

void loop() {
  populateData( data, SAMPLE_SIZE, readDistance );
  double median = getMedian( data, SAMPLE_SIZE );
  double average = getAverage( data, SAMPLE_SIZE );

  if( median > average + STANDARD_ERROR ) {
    return;
  }

  if( median < start - 2 ) {
    println( 0 );
  }
  else if( median < end ) {
    println( (int)(median - start) * 10.0 / (end - start) );
  }
  else {
    println( 10 );
  }
 
}

int readDistance() {
  sendPulse( trigPin );
  duration = pulseIn( echoPin, HIGH ); // milliseconds
  return duration * 0.0343 / 2;  
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


