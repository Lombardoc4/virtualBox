/*    SOSS-2 */
/* Simple OS Simulation v2 */
/* H.M. Hubey  CMPT-481 Spring 2012*/
/* Global Variables-- Dummy Functions-- Headers */
/* Added:: Dummy Functions to represent the outline */

#include <stdio.h>
#include <math.h>

// Macro to get random integer in a specified range
#define getRand(min,max) \
    ((rand()%(int)(((max)+1)-(min)))+(min))


#define PID 0
#define STATE 1
#define RID 2

#define READY 2
#define BLOCKED 0
#define RUNNING 1

#define SIMUON 1000
#define INTIMER 30

// ************* this is the beginning of student section *****
void collectSomeStats(void)
// this is a dummy function to be filled in
{
}

void newProcess(void)
// the student will do this later
{
}

void terminateProcess(void)
// the student will do this
{
}

void InitializeSys(void)
// this is a dummy function to be filled in
{
}

void regularInterrupts(void)
// this simulates generation of timer interrupts
{
}

void wp_Running_grabs_jthR_for_tslice (void)
// This is the main work horse
{
}


// ******* The Main Loop Starts Here ****************

int main() {
int t;
        InitializeSys();  // this kickstarts the system
for(t=0; t<SIMUON; t++){
// beginning of OS loop..the basic structure is contained here
	newProcess();
	regularInterrupts();
	wp_Running_grabs_jthR_for_tslice();
	terminateProcess();

} // end of OS loop
        collectSomeStats();   // this collects stats for analysis
}  // end of Main Pgm




