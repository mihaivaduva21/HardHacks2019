void println( String message ) {
  Serial.flush();
  Serial.println( message );
  delay( 50 );
}

void println( int value ) {
  Serial.flush();
  Serial.println( value );
  delay( 50 );
}

void print( String message ) {
  Serial.flush();
  Serial.print( message );
  delay( 50 );
}

void print( int value ) {
  Serial.flush();
  Serial.print( value );
  delay( 50 );
}
