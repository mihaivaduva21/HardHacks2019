#define BUFFER_SIZE 30

static long buffer[ BUFFER_SIZE ] = { 0 };
static int dataIndex = 0;

static double mean = 0;
static double maxMean = 0; /* max mean in buffer set */


void registerData( long data ) {
  dataIndex = dataIndex % BUFFER_SIZE;
  buffer[ dataIndex ] = data;
  dataIndex++;

  mean = (mean + data) / 2.0;

  if( mean > maxMean ) {
    maxMean = mean;
  }
  
}

long getMax() {
  return (long) maxMean;
}

