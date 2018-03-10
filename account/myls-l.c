
#include <stdio.h>
#include <stdlib.>
#include <sys/stat.h>

//#define rwrwrw (S_IRUSR | S_

void err_sys (const char* message); 


int main(int argc, char* argv[]){

		struct stat buf; 

	if (argc !=2)
		err_sys(" usage: ls<path_name>"); 
		
		DIR* directory = opendir(argv[1]); 
		if(directory == NULL)
		err_sys("cannot open"); 
			
			struct dirent* dirp; 
			
			while((dirp = readdir(directory)) != NULL){
			printf("%s", stat(dirp, buf));
				printf("%s\n", dirp -> d_name);
			}
			closedir(directory); 
			return 0; 
}

void err_sys (const char* message){
	printf("%s\n", message);
	exit(0);
}


