#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int i;
    int iterations;
    int status;

    if (argc != 2) {
        fprintf(stderr, "Usage: forkloop <iterations>\n");
        exit(1);
    }

    iterations = strtol(argv[1], NULL, 10);

    for (i = 0; i < iterations; i++) {

        int n = fork();

        if (n < 0) {
            perror("fork");
            exit(1);
        } else if (n == 0){
            i = iterations;
        } else {
            wait(&status);
        }

        printf("ppid = %d, pid = %d, i = %d\n", getppid(), getpid(), i);
    }

    return 0;
}
