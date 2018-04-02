/*      SOSS-3a  -- testing arrays                                      */
/*   Simple OS Simulation v3                                            */
/*   H.M. Hubey  CMPT-481 Spring 2012                                   */
/*   Inits PCB[][] two different ways                                   */
/*   Added:: Dummy Functions to represent the outline                   */
/*   Added:: General Outline                                             */

#include <stdio.h>
#include <math.h>
#include <cstdlib>

#define SIMUON 1000         // Simulation length
#define CYCLE 245     // this is the length of the interrupt timer
#define TIMER 0       // this defines an interrupt type
 
#define MAXPROCESS 9          // small VM will only run up to 9 processes
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

// Macro to get Interrupts
#define anyInterrupts(time) (time+1) % CYCLE
// Macro to get random integer in a specified range
#define getRand(min,max) \
    ((rand()%(int)(((max)+1)-(min)))+(min))

/* ******* Notice Global Variables declared outside main ********************
*            *********************                                         */
int t;
int runPid;                           // this is the pid of the running process
int PCB[MAXPROCESS][MAXSTATS];        // Process Control Block:: Maximum of 10 processes 
int RCB[MAXPROCESS];                  // Resource Control Block: '0' means 'no process'

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
   printf("switching process \n");
}


void wp_Running_grabs_jthR_for_tslice (void) {
// This is the main work horse
}

void printPCB(void) {
int r,c;
 printf("   The Initial Process Control Block \n");
   printf(" Legend: state=2 means READY-QUEUE \n");
   printf(" Legend: Locked-resource=0 means no-locks on any resources \n");
   printf("     pid          state          locked-resource \n");
    for (r=0; r<MAXPROCESS; r++){
      for (c=0; c<MAXSTATS; c++) {
       printf("      %d       ", PCB[r][c]);  // prints on one line
       }
       printf("\n");                          // provides a CR after the row is printed
     }
}


void test_1_PCB(void) {                // testing out loops and arrays  
int r,c ;                              // these are local vars; 
printf(" **************111111111111 TEST********* \n");
printf("  test_1_PCB \n");
 for (r=0; r<MAXPROCESS; r++){
       for(c=0; c < MAXSTATS; c++) {
         PCB[r][c] = 10*(r+1)+ (c+1);                   
       }
  } 
}

void test_2_PCB(void) {               // testing out loops and arrays
int r,c ;                             // these are local vars
printf(" *************2222222222  TEST   ********** \n");
printf("  test_2_PCB \n");
       for(r=0; r < MAXPROCESS; r++) {
         PCB[r][0] = 10*(r+1)+ 1; 
         PCB[r][1] = 10*(r+1)+ 2; 
         PCB[r][2] = 10*(r+1)+ 3;                   
       }
} 


void InitializeSys(void) {
// this is a dummy function to be filled in .....
int r,c ;
 for (r=0; r<MAXPROCESS; r++){
       for(c=0; c < MAXSTATS; c++) {
         PCB[r][c] = 0;                   
       }
   } 
}

void initSys(void) {
// this is a dummy function to be filled in
int r,c ;
  for (r=0; r<MAXPROCESS; r++){
   PCB[r][RID] = getRand(1,RANDPID);    // this creates pid's
     }
}




/* ******* The Main Loop Starts Here *******************************
*                                                                  *
*            *********************                                */
// Main program starts here
int main() {                 // Beginning of Main Program
int t;                        // Notice that PCB[][] is not declared here

           test_1_PCB();   // just testing arrays
           printPCB();
	   test_2_PCB();
           printPCB();
           //InitializeSys();      // fills up the array PCB with all zeros.
           //initSys();            // generates random PIDs
           //printPCB();
 for(t=0; t<SIMUON; t++){ //           beginning of OS loop..the basic structure is contained here
	newProcess();                     // student will create new processes with probability p1
	if(anyInterrupts(t) == TIMER) {
                 processSwitch();     // check for timer interrupts
        }
	wp_Running_grabs_jthR_for_tslice();  // this is the simulation of events
	terminateProcess();                // student will terminate processes with probability p2

} // end of OS loop
        collectSomeStats();        // this collects stats for analysis; to be done by student
}                                   // end of Main Pgm


