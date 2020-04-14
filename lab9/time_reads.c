/* The purpose of this program is to practice writing signal handling
 * functions and observing the behaviour of signals.
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

/* Message to print in the signal handling function. */
#define MESSAGE "%ld reads were done in %ld seconds.\n"

/* Global variables to store number of read operations and seconds elapsed. 
 */
long num_reads, seconds;

void handler(int code) {
  printf(MESSAGE, num_reads, seconds);
  exit(0);
}


/* The first command-line argument is the number of seconds to set a timer to run.
 * The second argument is the name of a binary file containing 100 ints.
 * Assume both of these arguments are correct.
 */

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: time_reads s filename\n");
        exit(1);
    }
    seconds = strtol(argv[1], NULL, 10);

    FILE *fp;
    if ((fp = fopen(argv[2], "r")) == NULL) {
      perror("fopen");
      exit(1);
    }

    //construct new sigaction struct

    struct sigaction new_sig; 
    new_sig.sa_handler = handler; 
    new_sig.sa_flags = 0; 
    sigemptyset(&new_sig.sa_mask); 
    sigaction(SIGPROF, &new_sig, NULL);  

    struct itimerval new_time;
    new_time.it_interval.tv_sec = 0; 
    new_time.it_interval.tv_usec = 0; 
    new_time.it_value.tv_sec = seconds; 
    new_time.it_value.tv_usec = 0; 
    if(setitimer(ITIMER_PROF, &new_time, NULL) < 0){
      perror("stitemer"); 
      exit(1); 
    } 

    /* In an infinite loop, read an int from a random location in the file,
     * and print it to stderr.
     */

    num_reads = 0;
    int num, output; 

    for (;;) {
      num = random() % 99; 
      fseek(fp, sizeof(int) * num, SEEK_SET);
      fread(&output, sizeof(int), 1, fp);
      printf("Count %ld: %d\n", num_reads, output); 
      num_reads++;       
    }
    
    return 1; // something is wrong if we ever get here!
}
