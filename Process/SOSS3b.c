/*      SOSS-3b -- global and local vars                 */
/*   Simple OS Simulation v3                             */
/*   H.M. Hubey  CMPT-481 Spring 2012                    */
/*   shows problems with global vs local vars            */
/*    Global Vars are defined outside Main()             */
/*  prints the PCB[][] twice -- right vs wrong           */
/***************************************************     */

#include <stdio.h>
#include <math.h>
#include <cstdlib>

#define SIMUON 1000         // Simulation length
#define CYCLE 245     // this is the length of the interrupt timer
#define TIMER 0       // this defines an interrupt type
 
#define MAXPROCESS 9          // small VM will only run up to 10 processes
#define MAXSTATS 3            // PCB only holds 3 stats <PID, STATE, RESOURCE>
#define RANDPID  10*MAXPROCESS // do not produce MAXPROCESS

#define PID 0            // used for PCB[]
#define STATE 1          // used for PCB; not for changing states of processes
#define RID 2            // can be used for Resource Control Block/List

#define READY 2               // state=2 means READY
#define BLOCKED 0             // process is blocked/waiting for a resource
#define RUNNING 1

#define FREE 0             // Resource is FREE to grab
#define LOCKED 1           // Resource is LOCKED

#define LOO PCB[0][2]		// Da Loo

// Macro to get Interrupts
#define anyInterrupts(time) (time+1) % CYCLE
// Macro to get random integer in a specified range
#define getRand(min,max) \
    ((rand()%(int)(((max)+1)-(min)))+(min))


// ************* this is the beginning of student section *****
void collectSomeStats(void) {
// this is a dummy function to be filled in
}

void newProcess(void) {
// the student will do this later
}

void terminateProcess(void){
// the student will do this
}

void processSwitch(void){
// this stub (dummy section) will switch processes; 
   printf("       timer interrupt ::: switching process \n");
}


void InitializeSys(void) {
// this is a dummy function to be filled in
int r,c ;
int PCB[MAXPROCESS][MAXSTATS];          // Process Control Block:: Maximum of 9 processes
   printf(" PID      STATE     Resource  \n");
  for (r=0; r<MAXPROCESS; r++){
   PCB[r][PID] = getRand(1,RANDPID);    // this creates pid's
    printf("     %d   ",PCB[r][PID]);
   PCB[r][STATE]=READY;               // all processes READY; later we'll set one of them RUN
     printf("     %d   ",PCB[r][STATE]);
   PCB[r][RID]=FREE;                  // no process has a lock on resources
   printf("     %d   \n",PCB[r][RID]);
// none of them are yet "running"
// there is no RUNNING_PID yet
 }
}

void regularInterrupts(void) {
// this simulates generation of timer interrupts
}

void wp_Running_grabs_jthR_for_tslice (void) {
// This is the main work horse
}


/* ******* The Main Loop Starts Here ****************
*                                                    *
*                                                     *
*            *********************                   */

int main() {                 // Beginning of Main Program
int t,r;
int runPid;                    // this is the pid of the running process
int PCB[MAXPROCESS][MAXSTATS];               // Process Control Block:: Maximum of 10 processes
int RCB[MAXPROCESS];                  // Resource Control Block: '0' means 'no process'

        InitializeSys();      // this kickstarts the system
for(t=0; t<SIMUON; t++){ //    beginning of OS loop..the basic structure is contained here

	newProcess();          // student will create new processes with probability p1
	if(anyInterrupts(t) == TIMER) {
                 processSwitch();     // check for timer interrupts
        }
	wp_Running_grabs_jthR_for_tslice();  // this is the simulation of events
	terminateProcess();    // student will terminate processes with probability p2
} // end of OS loop
        collectSomeStats();   // this collects stats for analysis; to be done by student

// note that the PCB[][] is "local" to main()
// see the next version
printf(" PID      STATE     Resource  \n");
  for (r=0; r<MAXPROCESS; r++){
    PCB[r][PID] = getRand(1,RANDPID);   
    printf("     %d   ",PCB[r][PID]);
    PCB[r][STATE]=READY;             
     printf("     %d   ",PCB[r][STATE]);
    PCB[r][RID]=FREE;                
   printf("     %d   \n",PCB[r][RID]);
// none of them are yet "running"
// there is no RUNNING_PID yet
 }

}                             // end of Main Pgm


