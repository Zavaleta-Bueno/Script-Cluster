#include <stdio.h>
#include <math.h>
#include <stdlib.h>



static long MULTIPLER = 1366;
static long ADDEND = 150889;
static long PMOD = 714025;


double random_last;
double random_low; 
double random_hi;

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


double randomx(){
	long random_next;
	double ret_val;

	// calculando un numero aleatorio entero desde cero a mod

	random_next = fmod( (MULTIPLER * random_last+ ADDEND) , PMOD);
	random_last = random_next;

	//Cambia el rango predeterminado


	ret_val = ((double)random_next/(double)PMOD) * (random_hi-random_low) + random_low;   
	return ret_val;	
}






int  main(int argc, char *argv[]) {


	int num_trials;
   	double PI25DT=3.141592653589793238462643;
   	double x,y;
   	int i,count=0; /* # nuemro de terminos del 1er cuadrate de un circulo */
   	double z;
   	double pi;


   	count=0;
   	num_trials= atoi(argv[1]);

   	seed(1,714025);

   	printf("El numero de trials es : %d \n",num_trials);

   	  for ( i=0; i<num_trials; i++) {
   	  	
      	x = randomx()/PMOD;
      	y = randomx()/PMOD;
      	z = x*x+y*y;
      	if (z<=1) count++;
      }

   pi=(double)count/num_trials*4;
   printf("# of trials= %d , estimate of pi is %g \n",num_trials,pi);
   printf("El error relativo %.16f\n",fabs(pi - PI25DT)/PI25DT);





	return(0);
}