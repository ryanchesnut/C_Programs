//Ryan Chesnut
//linux-c
//assignment 6

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

void err_sys (const char* message);


int main(){

	int i;  
	int k = 1; 
	int j = 0;
	pid_t pid;
	char lowerCase [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
	char upperCase [] =  {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
	
	
	int fd2 = creat ("alphabet.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd2 < 0)
    err_sys ("error in creat");
	
	
  pid = fork();
  if (pid < 0){
    err_sys("fork error");
  }
  else if (pid == 0){	/* child */
  	for(i=0; i<26; i++){
  		int size = pwrite(fd2, &lowerCase[i], sizeof(char), k);
  		if(size < 1)
  				err_sys("error writing");
  	  	k = k + 2;
  	}
  }
  
  else if(pid > 0) {	/*parent*/
    for(i=0; i<26; i++){
  		int size = pwrite(fd2, &upperCase[i], sizeof(char), j);
  			if(size < 1)
  				err_sys("error writing");
  	  	j = j + 2; 
  	}
  	close(fd2); 
  	exit(0);
  }
  
 
  return 0; 
}

void err_sys (const char* message)
{
  printf ("%s\n", message);
  exit (0);
}
