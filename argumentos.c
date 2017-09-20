#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>




double dx_arctan(double x)
{    
    return (1.0 / (1.0 + x*x));
}


int obtener(){
    return 10;
}

//int main(int argc, char *argv[])
int main(int argc, char *argv[])

{
    int n;
    double PI25DT = 3.141592653589793238462643;
    double mypi, h, pi, i, sum, x, a, startwtime, endwtime;
    int myid, numprocs, resultlen;
    char name[MPI_MAX_PROCESSOR_NAME] ; 

    MPI_Init(&argc,&argv);

    /* Hacer esto para evitar error */    
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(name, &resultlen); 

    /* Mostrar IDs de todos los prrocesos*/
    //printf("This is Process-%d/%d running on %s \n",myid,numprocs,name);
    fflush(0);
    MPI_Barrier(MPI_COMM_WORLD);

    /* Obtener la informacion del tiempo de ejecucion */
    if(myid == 0) 
    {
        //printf("Este programa usa el proceso %d \n", numprocs);
	
       

	 n = atoi(argv[1]);
        

        //printf("The number of intervals = %d \n", n); 

        startwtime = MPI_Wtime();
    }

    /* Comparte los intervalos con otros procesos */
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    sum = 0.0;
    h   = 1.0/n;
    /* Compute and Sum the "Heights" of each bar of the integration */
    for (i=myid+0.5; i<n; i+=numprocs)
    {
        sum += dx_arctan(i*h);
    }
    /* Multiply by the "Widths" of each bar and 
       4.0 (arctan(1)=Pi/4) */
    mypi = 4.0*h*sum;

    /* Consolidate and Sum Results */
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid == 0)
    {
        endwtime = MPI_Wtime();
       /* printf("PI es aproximadamente %.16f, Error es %.16f\n",
                pi, fabs(pi - PI25DT)); 
        printf("El tiempo de ejecucion es = %f\n", endwtime-startwtime);*/
        printf("%f      %.16f\n",endwtime-startwtime,fabs(pi - PI25DT)); 
    }
    MPI_Finalize();
    //return 0;
    //return(endwtime-startwtime);
    obtener();
    return(0);
}



