/*    SOSS-1b */
/* Simple OS Simulation v1 */
/* H.M. Hubey  CMPT-481 Spring 2012*/
/* Global Variables-- Dummy Functions-- Headers */


#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <time.h>

// define some constants for easy comprehension
#define PID 0
#define STATE 1
#define RID 2

#define READY 2
#define BLOCKED 0
#define RUNNING 1

// Macro to get random integer in a specified range
#define getR0(min,max) ((rand()%(int)(((max)+1)-(min)))+(min))

#define getR1(min, max) rand()%(max-min)+min

#define getR1b(min, max) (rand()%(max-min)+min)



int main()
{
int i;
srand(time(NULL));
int min = 1, max = 9;


for (i=0;i<20;i++)
    {  
     int R1= rand()%(max-min)+min;
     int R0 = getR0(1,9);
     int R1b = getR1b(1,9);

     printf("R0 (using orig Macro)  %d           %d              %d  \n",R0, 2*R0, R0/2);	
     printf("R1 (using srand)       %d           %d              %d  \n",R1, 2*R1, R1/2);
     printf("R1b (using orig Macro  %d           %d              %d  \n",R1b, 2*R1b, R1b/2);
     printf("    \n");

    }  
}
