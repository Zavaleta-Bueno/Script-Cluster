







typedef struct
{
	float pos[3][N];
	float vel[3][N];
	float m[N];
	void integr();
	
} NBody;








void integr () 
{

// medida del  CPUtime
start=clock();
for(int t=0;t<tf;t=t+dt)
	force(n, pos, vel, m, dt)

// medida CPUtime
end = clock();
cpuTime= difftime(end,start)/(CLOCKS_PER_SEC)
…
}





void force(int n, float pos[][..],….,float vel[][..], float m[..], float dt) 
{
 // sume over i
  for (int i=0; i<n; i++)
  {
	float my_r_x = pos[0][i];
    float my_r_y = pos[1][i];
	....  
 // sume over j
	for (int j=0; j<n; j++)
	{
 		if(j!=i)   // avoid i=j
		{
// compute accelerations
	float dx = pos[0][j]-my_r_x; // 1 flop
    float dy = pos[1][j]-my_r_y; // 1 flop

    a_x += G*m[j]/(dx*dx);  // 4 flops    
    a_y += G*m[j]/(dy*dy);
		…
		}
	}



int main(int arg, char char *argv[]){


// definido en la estructura 
Nbody galaxy;

// inicializando propiedades
galaxy.init();

// integrate forces
galaxy.integr();



//https://github.com/harrism/mini-nbody/blob/master/nbody.c





return(0);



} 