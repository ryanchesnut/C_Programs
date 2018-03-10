#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFF_SIZE 30

void err_sys (const char* message);

int main ()
{  
  int amount, current, result, charsLeft; 
  int i; 
  int k =1;  
  
  // --Open files---// 
  int fd1 = open ("testFile.txt", O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd1 < 0)
    err_sys ("error in open");
  int fd2 = creat ("copy.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd2 < 0)
    err_sys ("error in creat");
  //------------------------------//
  
  int fileSize = lseek(fd1, 0, SEEK_END);  
  int placeHolder;
  char revBuf[BUFF_SIZE]; 
  char buf[BUFF_SIZE];
  
  //---Case where the filesize is smaller than or equal the buffer--//
  if(fileSize-1 <= BUFF_SIZE){
  	placeHolder = 0;
  	char buf[fileSize-1];
  	char revBuf[fileSize-1];
  	current = lseek(fd1, placeHolder, SEEK_SET);
  	if(current < 0)
    	err_sys("error moving in file"); 
  	amount = read(fd1, buf, fileSize-1);
  	if (amount < 0)
      err_sys ("error in reading");
   	 
  	for(i=0; i<fileSize-1; i++){
  	  revBuf[i]= buf[fileSize-1-k]; 	
  	  k++;
 	}
  	result = write (fd2, revBuf, fileSize-1);
  	if (result < amount)
	  err_sys ("write error");

  }
  //-- Case Where the file size is bigger than the buffer --//
  else{
  	placeHolder = fileSize - BUFF_SIZE-1; 
   	charsLeft= fileSize-1; 
    do { 
    	if(charsLeft < BUFF_SIZE){
    		placeHolder = 0; 
    		current = lseek(fd1, placeHolder, SEEK_SET);
    		if(current < 0)
    			err_sys("error moving in file"); 
    		amount = read(fd1, buf, charsLeft);
    		if (amount < 0)
      			err_sys ("error in reading");
      		int k =1; 
			for(i=0; i<charsLeft; i++){
  	  			revBuf[i]= buf[charsLeft-k];	
  	  			k++;
 			}
 			result = write (fd2, revBuf, charsLeft);
  			if (result < amount)
	  			err_sys ("write error");
 			charsLeft = 0; 
    	}
     	else{
    		current = lseek(fd1, placeHolder, SEEK_SET);
    		if(current < 0)
    			err_sys("error moving in file"); 
    		amount = read(fd1, buf, BUFF_SIZE); 
  			if (amount < 0)
        		err_sys ("error in reading"); 
    		int k =1; 
  			for(i=0; i<BUFF_SIZE; i++){
  				revBuf[i]= buf[BUFF_SIZE-k]; 	
  				k++;
  			}
    		result = write (fd2, revBuf, BUFF_SIZE);
    		if (result < amount)
	  			err_sys ("write error");
  		  	placeHolder = placeHolder - BUFF_SIZE; 
  			charsLeft = charsLeft - BUFF_SIZE; 
  		}
  		
      }while(charsLeft >0); 
 	}
  close (fd1);
  close (fd2);
  return 0;
}

void err_sys (const char* message)
{  
  printf ("%s\n", message);
  exit (0);
}

