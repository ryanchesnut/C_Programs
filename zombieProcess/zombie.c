//Ryan Chesnut
//linux-c
//assignment 7

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err_sys (const char* message);

int main (){
	pid_t pid;
	if ((pid = fork()) < 0){		
		err_sys("error in fork");
	}
	else if (pid == 0){	
	printf("child pid: %d\n", getpid());
	exit(0);
	}
	if (pid > 0){
		printf("parent pid: %d\n", getpid());
		sleep(2);
		system("ps");
	}
	return 0;
}

void err_sys (const char* message){
	printf ("%s\n", message);
	exit (0);
}
