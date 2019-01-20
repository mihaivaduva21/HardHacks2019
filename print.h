#include <SoftwareSerial.h>
SoftwareSerial BT( 10, 11 ); // RX, TX

void println( String message ) {
  Serial.flush();
  BT.flush();
  Serial.println( message );
  BT.println( message );
  delay( 50 );
}

void println( int value ) {
  Serial.flush();
  BT.flush();
  Serial.println( value );
  BT.println( value );
  delay( 50 );
}

void print( String message ) {
  Serial.flush();
  BT.flush();
  Serial.print( message );
  BT.print( message );
  delay( 50 );
}

void print( int value ) {
  Serial.flush();
  BT.flush();
  Serial.print( value );
  BT.print( value );
  delay( 50 );
}
