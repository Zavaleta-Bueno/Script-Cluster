#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mpi.h>


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




int main(int argc, char* argv[])
{
	int nintervalos;
	int myid;						//id del rango del proceso de hold
	double x,y;						//x,y value for the random coordinate
	int i;
        int count=0;						//Count holds all the number of how many good coordinates
	double z;						//Used to check if x^2+y^2<=1
	double pi;						//holds approx value of pi
	int reducedcount;					//total number of "good" points from all nodes
	int reducednintervalos;					//total number of ALL points from all nodes

	MPI_Init(&argc, &argv);					//Start MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);			//get rank of node's process

	nintervalos = atoi(argv[1]);
	seed(1,714025);


	if(myid != 0)
	{
						//Give rand() a seed value
		for (i=0; i<nintervalos; ++i)				//main loop
		{
			x = randomx()/PMOD;			//gets a random x coordinate
			y = randomx()/PMOD;			//gets a random y coordinate
			z = ((x*x)+(y*y));			//Checks to see if number in inside unit circle
			if (z<=1)
			{
				++count;			//if it is, consider it a valid random point	
			}	
		}			
	}	

	MPI_Reduce(&count, &reducedcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&nintervalos, &reducednintervalos, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	reducednintervalos -= nintervalos;					//to compensate for no loop on master node

	if (myid == 0)						//if root process
	{      
		//p = 4(m/n)
		pi = ((double)reducedcount/(double)reducednintervalos)*4.0;	
		printf("Pi: %f\n", pi);			
	}
	MPI_Finalize();						//Close the MPI instance
	return 0;
}