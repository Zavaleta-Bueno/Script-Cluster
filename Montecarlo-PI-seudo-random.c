#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


static long MULTIPLER = 1366;
static long ADDEND = 150889;
static long PMOD = 714025;


double random(){
	long random_next;
	double ret_val;

	// calculando un numero aleatorio entero desde cero a mod

	random_next = (MULTIPLER * random_last+ ADDEND) % PMOD;
	random_last = random_next;

	//shit into preset range

	ret_val = ((double)random_next/(double)PMOD) * (random_hi-random_low) + random_low;   
	return ret_val;	
}



void seed(double low_in, double hi_in ){

	if(low_in < hi_in){

		random_low =low_in;
		random_hi = hi_in;

	}

	else {
		random_low = hi_in;
		random_hi  = low_in;
	}

	random_last = PMOD/ADDEND; 

} 



int main(int argc, char *argv[]) {















	return(0);
}