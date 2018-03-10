//Ryan Chesnut 
//linux_c
//assignment 8

#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

void err_sys (const char* message);
int file_length(FILE *f);
int numOfRecords;

int main (int argc, char* argv[])
{
  //---Add Function --//
  if(strcmp(argv[2], "add") == 0){ 
    if (argc < 6)
      err_sys ("missing command line argument");
    
    FILE* f = fopen (argv[1], "a");
    if (f == NULL)
      err_sys ("error in opening file");
    int filesize = file_length(f);
  	numOfRecords = filesize/24;
  	int c = atol(argv[5]); 
  	float p = atof(argv[4]);
  	data* d = create_data (argv[3], p, c);
  	filesize = file_length(f);
  	if(filesize == 0){
 		int size = fwrite (d, sizeof(data), 1, f);
  		if (size != 1)
    		err_sys ("error in writing to file");
    	fclose(f);
    }
    	
    FILE* f1 = fopen (argv[1], "r+");
    int i = 0;
    int found = 0;
    for(i =0; i<numOfRecords; i++){
    	data d1;
    	int size = fread (&d1, sizeof(data), 1, f1);
		if (size != 1)
  	  		err_sys ("error in reading from file");
    	if(strcmp(d1.name, "expunged") == 0){
    		fseek(f1, (long)i*24, SEEK_SET);
    		int size = fwrite (d, sizeof(data), 1, f1);
    		if (size != 1)
    			err_sys ("error in writing to file");
    		fclose(f1);
    		found = 1;
    		break;
    		}
    	}
   
    if(found == 0){
    	fseek(f, filesize, SEEK_SET);
    	int size = fwrite (d, sizeof(data), 1, f);
    	if (size != 1)
    		err_sys ("error in writing to file");
    
    }
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
    numOfRecords = filesize/24; 
    float grandTotal = 0.0;
    float total = 0.0; 
	int i;  	
	for(i =0; i<numOfRecords; i++){
	data d;
	 
  	int size = fread (&d, sizeof(data), 1, f);
  	if (size != 1)
    	err_sys ("error in reading from file");
  	else{
  		if (strcmp (d.name, "expunged") !=0) 
    		display_data (&d);
    	total = (d.price) * (d.count); 
    	grandTotal += total; 	
    	}
    	
    }
    printf("\t\t     Total = %f\n", grandTotal);
    fclose(f); 
  
  // --Delete Function --/ /
  }else if(strcmp(argv[2], "delete") == 0){
  	char name[15] = "expunged";
  	float s =0.0;
  	int t = 0;
  	if(argc < 4) 
      err_sys ("missing command line argument");
    
    FILE* f = fopen (argv[1], "r+");
    
    if (f == NULL)
      err_sys ("error in opening file");
   	int k = 24;
   	int	filesize = file_length(f);
  	int numOfRecords = filesize/24;
  	int found = 0; 
  	int i;
  	for(i =0; i<numOfRecords; i++){
  		data d;
  		int size = fread (&d, sizeof(data), 1, f);
		if (size != 1)
  	  		err_sys ("error in reading from file");
  		char* tempName = d.name;
  	  	if (strcmp(tempName, argv[3]) == 0){
  	  		data* d1 = create_data (name, s, t);
  	  		fseek(f, (long)i*k, SEEK_SET);
  	  		int size2 = fwrite (d1, sizeof(data), 1, f);
  	    	if (size2 != 1)
    			err_sys ("error in writing to file");
    		found = 1;
  	  		}		
  	}
  	if(found == 0)
  	  	printf("no record found\n");
  	  		
  	fclose(f);
  	
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

