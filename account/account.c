//Ryan Chesnut
//Assignment 2
//Linux W/ C

#include "account.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int all_digits (char* s)
{
  assert (s != NULL);
  int i = 0;
  while (i < strlen (s) && isdigit (s[i]))
    i++;
  return i == strlen (s);
}
//Checks for valid account
int is_valid_owner (char* n)
{
  return n != NULL && strlen (n) > 0;
}

int is_valid_account_num (char* a_num)
{
  return a_num != NULL && strlen(a_num ) > 1 && all_digits(a_num);
}

//Create an account

account* create_account(char* owner, float init_balance, char* account_num){
	account* a = NULL;
	if(is_valid_owner(owner) && init_balance >= 0 && is_valid_account_num(account_num)  ){
		a = malloc(sizeof (account));
		a -> owner = malloc((strlen(owner) + 1)* sizeof(char));
		strcpy(a -> owner, owner);
		a -> balance = init_balance;
		a -> account_num = malloc((strlen(account_num) + 1)* sizeof(char));
		strcpy(a -> account_num, account_num);
	}
	return a;
}

//Print account details
void display_account(account* a){
	assert (a != NULL);
  	printf ("owner: %s\tbalance: $%.02f\taccount number: %s\n", a -> owner, a -> balance, a-> account_num);
}

//Deposit money
int deposit(account* a, float deposit){
	assert(a != NULL);
	if(deposit <= 0.0){
		return 0;
	}
	else{
		a -> balance += deposit;
		return -1;
	}
}

//Withdraw money
int withdraw(account* a, float withdraw){
	assert(a != NULL);
	if ( withdraw < 0.0 )
		return 0;
	else{
		a -> balance -= withdraw;
		return -1;

	}
}

//Delete account
void delete_account(account* a){
	assert (a != NULL);
  	if (a -> owner != NULL)
    	free (a -> owner);
  	if (a -> account_num != NULL)
    	free (a -> account_num);
    	a -> balance = 0.0;
  	free (a);
}
