/*    SOSS-1b */
/* Simple OS Simulation v1 */
/* H.M. Hubey  CMPT-481 Spring 2012*/
/* Global Variables-- Dummy Functions-- Headers */

// Issue with the same numbers are generated everytime you run prog.
// This is not an issue in 1b

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

#define getR1(min, max) (rand()%(max-min)+min)

#define getR1b(min, max) (rand()%(max-1+min)-min)


int main()
{
int i;
for (i=0;i<20;i++)
    {  
	int first=getR0(1,9); 
	int fmult = 3*first;
	int fdiv = first/3;
	int second=getR1(1,9);
	int smult=3*second;
	int sdiv=second/3;
	int third=getR1b(1,9);
	int tmult=3*third;
	int tdiv=third/3;

     printf("R0                   %d           %d              %d  \n",first, fmult, fdiv);     
     printf("R1                   %d           %d              %d  \n",second,smult,sdiv);
     printf("R1b(using new Macro) %d           %d              %d  \n",third, tmult, tdiv);
     printf("    \n");
    }  
}
