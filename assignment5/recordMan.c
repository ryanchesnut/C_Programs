//Ryan Chesnut 
//linux_c
//assignment 5

#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void err_sys (const char* message);
int file_length(FILE *f);

int main (int argc, char* argv[])
{
  //---Add Function --//
  if(strcmp(argv[2], "add") == 0){
  
    if (argc < 6)
      err_sys ("missing command line argument");
    
    FILE* f = fopen (argv[1], "a");
    if (f == NULL)
      err_sys ("error in opening file");
      
  	int c = atol(argv[5]); 
  	float p = atof(argv[4]);
  	data* d = create_data (argv[3], p, c);
 	int size = fwrite (d, sizeof(data), 1, f);
  	if (size != 1)
    	err_sys ("error in writing to file");
  	fclose (f);
  	display_data(d); 
  }
  
  //--Report function --//
  else if(strcmp(argv[2], "report") == 0){
    
    if(argc < 3) 
      err_sys ("missing command line argument");
    
    FILE* f = fopen (argv[1], "r");
    if (f == NULL)
      err_sys ("error in opening file");
   	
    int filesize = file_length(f);
    int numOfRecords = filesize/24; 
    float grandTotal = 0.0;
    float total = 0.0; 
	int i;  	
	for(i =0; i<numOfRecords; i++){
	data d;
	
  	int size = fread (&d, sizeof(data), 1, f);
  	
  
  	if (size != 1)
  	  	err_sys ("error in reading from file");
  	else{
    	display_data (&d);
    	total = (d.price) * (d.count); 
    	grandTotal += total; 	
    	}
    	
    }
    printf("\t\t     Total = %f\n", grandTotal);
    fclose(f); 
  
  // --Delete Function --/ /
  }else if(strcmp(argv[2], "delete") == 0){
  	
  	if(argc < 4) 
      err_sys ("missing command line argument");
    
    FILE* f = fopen (argv[1], "r+");
    FILE* ft = fopen ("temp.dat", "w");
    
    if (f == NULL)
      err_sys ("error in opening file");
   	data d;
   	int	filesize = file_length(f);
  	int numOfRecords = filesize/24; 
  	int i;
  	for(i =0; i<numOfRecords; i++){
  	char* tempName = d.name; 
		int size = fread (&d, sizeof(data), 1, f);
		if (size != 1)
  	  		err_sys ("error in reading from file");
  	  	if (strcmp(tempName, argv[3]) != 0){
  	  		int size2 = fwrite (&d, sizeof(data), 1, ft);
  	    	if (size2 != 1)
    			err_sys ("error in writing to file");
  	  		}
  	  		
  	}
  	fclose(f);
  	fclose(ft);
  		FILE* f1 = fopen (argv[1], "w");
   	    FILE* ft1 = fopen ("temp.dat", "r");
   	    int fs = file_length(ft1); 
   	    numOfRecords = fs/24; 
   	    data d1;
   	    for(i =0; i<numOfRecords; i++){
   	   	    int size = fread (&d1, sizeof(data), 1, ft1);
			if (size != 1)
  	  			err_sys ("error in reading from file");
  			int size2 = fwrite (&d1, sizeof(data), 1, f1);
  			if (size2 != 1)
    			err_sys ("error in writing to file");
  		}
  		fclose(ft1);
  		fclose(f1);
   }
   else {
   		printf("%s\t:", argv[2]); 
		err_sys("no such command"); 
	}
	
	
  return 0;
}

int file_length(FILE *f)
{
	int pos;
	int end;

	pos = ftell (f);
	fseek (f, 0, SEEK_END);
	end = ftell (f);
	fseek (f, pos, SEEK_SET);

return end;
}

void err_sys (const char* message)
{
  printf ("%s\n", message);
  exit (0);
}

