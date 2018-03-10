//Ryan Chesnut 
//Assignment 2
//Linux W/ C 

#ifndef _ACCOUNT_H


/*
The goal of this assignment is to reinforce and extend a student's knowledge of C.  Specifically, this assignment is to implement a bank account.  A bank account will consist of 3 attributes:

    owner - string which is not NULL and has at least 1 character
    account number - string which is not NULL, has at least 1 character, all characters are digits
    balance - must be non-negative
*/

typedef struct bank_account{

   char* owner;
   char* account_num;
   float balance;

}account;

int all_digits (char* s);
int is_valid_owner (char* n);
int is_valid_account_num (char* a_num);


/*
        input: owner, initial balance, account number
        output: pointer to a bank account
        return NULL is any input is not valid

*/

account* create_account(char* owner, float init_balance, char* account_num);

/*
        input - pointer to a bank account
        displays all attributes of the account - format not specified
        assertion used to verify pointer to the bank account is not NULL
*/

void display_account(account* a);

/*
        input - pointer to bank account (cannot be NULL) & amount of deposit (must be positive)
        postcondition: amount has been added to balance
        returns false if amount of deposit is not positive - true otherwise
        assertion used to verify pointer to the bank account is not NULL
*/

int deposit(account* a, float deposit);

/*
        input - pointer to bank account (cannot be NULL) & amount of withdrawal (must be positive & cannot be larger than the balance
        postcondition: amount has been subtracted from balance
        returns false if amount of withdrawal is not valid - true otherwise
        assertion used to verify pointer to the bank account is not NULL
*/

int withdraw(account* a, float withdraw);

/*
        input - pointer to bank account 
        postcondition: all memory allocated to the bank account has been deallocated
        does nothing if input pointer is NULL
*/

void delete_account(account* a);

#endif

