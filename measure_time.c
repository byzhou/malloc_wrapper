
#include <stdio.h>
#include <time.h>

void measure_time(void){

	struct timespec tstart = {0, 0}, tend = {0, 0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);	
	// some operations happened
	clock_gettime(CLOCK_MONOTONIC, &tend);	
	double timespan	= (double)tend.tv_sec + 1.0e-9 * tend.tv_nsec -
					(double)tstart.tv_sec - 1.0e-9 * tstart.tv_nsec;
	fprintf(stderr, "[MEASURETIME] Time %.9f passed.\n", timespan);


}
