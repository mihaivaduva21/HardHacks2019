void populateData( int * data, int dataSize, int (* readSensor)() ) {
  int value = 0; /* data from sensor pin */
  
  delay( 50 );
  
  for( int index = 0; index < dataSize; index++ ) {
    /* reading data */
    value = readSensor();
    //Serial.println( value );
    data[ index ] = value;
    //delay( 1 ); /* allow delay for more representative data sample */
  }
  
}

double getAverage( int * data, int dataSize ) {
  long total = 0;      /* .sum of data element values */
  long value = 0; /* new data element */
  
  for( int index = 0; index < dataSize; index++ ) {
    /* sum for total */
    total += data[ index ];
  }
  
  return total / dataSize;
}


double getStanDev( int * data, int dataSize, double average ) {
  long  deviations = 0; /* data point deviations */
    
  for( int index = 0; index < dataSize; index++ ) {
    /* treat all points equally */
    deviations += sq( data[index] - average );
  }

  /* unbiased sample size hence (dataSize - 1) */
  return sqrt( deviations / (dataSize - 1) ); 
}

int compareFunc( const void * pt1, const void * pt2 ) {
  return *((int *)pt1) < *((int *) pt1);
}

double getMedian( void * data, size_t dataSize ) {
  qsort( data, dataSize, sizeof(int), compareFunc );
  return *((int *) data + (int) (dataSize / 2.0) );
}


