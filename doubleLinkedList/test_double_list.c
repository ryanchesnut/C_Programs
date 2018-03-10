//Ryan Chesnut
//assignment 3
//linux and c

#include "double_list.h"
#include <stdio.h>
#include <assert.h>

void display_list (const double_list* dl);
void display_reverse_list(const double_list* dl);

int main ()

{
  double_list* dl = create_list();
 // append (dl, "aaa");
 // prepend (dl, "bbb");
 // insert (dl, "ccc", 1);
 // insert (dl, "ddd", 3);
 // display_list (dl);
 
 //remove_from_list(dl, 3); 
 // display_list (dl);
  
 // set (dl, "eee", 1);
  for(int i =0; i < 20; i++){
  	append(dl, (void*)i);
  
  }
  display_list(dl);
 display_reverse_list(dl);
 // delete_list(dl);

  return 0;
}

void display_list (const double_list* dl){
	
  for (int i = 0; i < size(dl); i++){
    int s = (int)get(dl,i);
    printf ("%d\n", s);
  }
  printf("\n");
}

void display_reverse_list(const double_list* dl){

	for(int i=size(dl)-1; i>=0; i--){
		int s = (int)get(dl,i);
    	printf ("%d\n", s);
	}
	printf("\n");

}






