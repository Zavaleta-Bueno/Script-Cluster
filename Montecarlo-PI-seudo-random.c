#include <stdio.h>
#include <math.h>


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


double random(){
	long random_next;
	double ret_val;

	// calculando un numero aleatorio entero desde cero a mod

	random_next = fmod( (MULTIPLER * random_last+ ADDEND) , PMOD);
	random_last = random_next;

	//Cambia el rango predeterminado


	ret_val = ((double)random_next/(double)PMOD) * (random_hi-random_low) + random_low;   
	return ret_val;	
}






int main() {
	int a;
	double aleatorio;
	printf("Esto es una prubea de aleatorios \n");

	printf("Ingrese una opcion diferente de cero \n");
	scanf("%d",&a);
	seed(100,10000);

	aleatorio=random();
	printf("El last %lf\n",random_last);
	printf("%lf \n",aleatorio);

	/*while(a!=0){
		printf("%lf \n",random);
		printf("Ingrese una opcion diferente de cero \n");
		scanf("%d",a);
	}*/


	return(0);
}