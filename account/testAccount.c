
//Ryan Chesnut 
//Assignment 2
//Linux W/ C 

#include "account.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	account* bad1 = create_account(12, -50.00, "ABCD"); 
	account* a1 = create_account("Joe", 5000.50 , "1134195435");
	account* a2 = create_account("Ryan", 100000.00, "3489032848"); 
	display_account(bad1); 
	display_account(a1); 
	display_account(a2); 
	deposit(a1, 400.00); 
	deposit(a1, -400.00); 
	display_account(a1);
	withdraw(a1, 200.00); 
	display_account(a1); 
	delete_account(a1);
	delete_account(a2);
	display_account(a1); 
	display_account(a2); 
	return 0; 

}


