#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int  main(int argc, char *argv[])
{
   int num_trials;
   double PI25DT=3.141592653589793238462643;
   double x,y;
   int i,count=0; /* # nuemro de terminos del 1er cuadrate de un circulo */
   double z;
   double pi;

   //printf("El numero de trials es 10: ");
   //scanf("%d",&niter);

   /* initialize random numbers */
   srand(SEED);
   count=0;

   num_trials= atoi(argv[1]);

  

   printf("El numero de trials es : %d \n",num_trials);


   for ( i=0; i<num_trials; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/num_trials*4;
   printf("# of trials= %d , estimate of pi is %g \n",num_trials,pi);
   printf("El error relativo %.16f\n",fabs(pi - PI25DT)/PI25DT);


   return (0);
}

