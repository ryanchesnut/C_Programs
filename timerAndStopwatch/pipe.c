//Ryan Chesnut
//linux_c
//Assignment 10

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>


#define MAXLINE 4096

void err_sys (const char* message);

int main (void) {
  int status;
  int fd[2];
  pid_t pid;
 
  if (pipe(fd) < 0)
    err_sys("error in pipe");

  if ((pid = fork()) < 0)
    err_sys("error in fork");
 
  else if (pid > 0) {
	   
	  	if (close(fd[0]) == -1) 
      	  err_sys("error in close");
            	
        if (dup2(fd[1], STDIN_FILENO) != STDIN_FILENO)
		  err_sys("dup2 fd[1] error to stdin");
      	dup2(fd[1], STDOUT_FILENO); 
      	
      	if(execlp("ls", "ls", "-l", NULL) < 0)
     		err_sys("error in execlp");
      	execlp("ls", "ls", "-l", NULL);

     	if (wait(&status) != pid)
		   err_sys("error in wait");
    }
  else {
    	if (close(fd[1]) == -1) 
      	  err_sys("error in close");
     	close(fd[1]);
     	
     	if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			err_sys("dup2 fd[2] error to stdin");
     	dup2(fd[0], STDIN_FILENO);
     	
     	if(execlp("sort", "sort", NULL) < 0)
     		err_sys("error in execlp"); 
     	execlp("sort", "sort", NULL);
     	
     	exit(status);
    }
  
	return(0);
}


void err_sys (const char* message){
  printf("%s\n", message);
  exit(0);
}
