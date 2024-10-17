#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_worker(int lower, int upper) {
    pid_t pid = fork();
    if (pid == 0) {
        char lower_str[10], upper_str[10]; 	//create space for storing string
        sprintf(lower_str, "%d", lower);	//convert from int to string for execl func
        sprintf(upper_str, "%d", upper);	//^^
        execl("./worker", "./worker", lower_str, upper_str, (char *) NULL);	//replace current process with worker
    } else if (pid > 0) {
        wait(NULL);	//wait for worker to finish
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {	//check if args are correct
        printf("Usage: %s <number_of_workers> <upper_bound>\n", argv[0]);	//error message
        return 1;
    }

    int workers = atoi(argv[1]);	//store args from cli to int(convert)
    int uBound = atoi(argv[2]);		//^^
    int rpWorker = uBound / workers;

    for (int i = 0; i < workers; i++){	//split wokers, execute from lower-upper
    int lower = i * rpWorker + 1;
    int upper = (i + 1) * rpWorker;

    create_worker(lower, upper);	//create woker
}


    return 0;
}

