//Ryan Chesnut
//linux c
//assignment 9

// Discussed high level with Mazdak Arzi // 

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

static void sig_alarm (int signo);
static void sig_int(int signo);
static void sig_quit(int signo);
void err_sys (const char* message);

static jmp_buf alarm_jmp;
int toggle = 0;

int main () {
  int time = 0;

  if (signal (SIGALRM, sig_alarm) == SIG_ERR)
    err_sys ("alarm signal error");
    
  alarm (1);
 
  if (sigsetjmp (alarm_jmp, 1) != 0) {
   //if (signal(SIGINT, sig_int) == SIG_ERR);
  	//	err_sys ("sigint signal error"); 
  	 signal(SIGINT, sig_int);
  		
  	 //if (signal(SIGQUIT, sig_quit) == SIG_ERR);
  	//	err_sys ("quit signal error");
  	 signal(SIGQUIT, sig_quit);
   	
   	if (toggle == 0) {
      time++;
      printf ("%d\n", time);
      alarm (1);
      }
     else{
       	while(toggle != 0);
      	siglongjmp (alarm_jmp, 1);
     }
    }
  	
  while(1);
    
 return 0;
}

static void sig_quit(int a){
	exit(0);
}

static void sig_int(int a){
	if(toggle == 0){
		toggle = 1;
	}
	else{
		printf("\n"); 
		toggle = 0;
	}	
 	
}
static void sig_alarm (int signo)
{
  siglongjmp (alarm_jmp, 1);
}

void err_sys (const char* message)
{
  printf ("%s\n", message);
  exit (0);
}

