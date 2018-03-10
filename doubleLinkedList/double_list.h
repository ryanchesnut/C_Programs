//Ryan Chesnut
//assignment 3
//linux and c

#ifndef _LIST_H
#define _LIST_H

typedef struct list_node
{
  void* item;
  struct list_node* next;
  struct list_node* prev;
}node;

typedef struct list
{
  node* front;
  node* rear;
  int size;
}double_list;

/**************************************************
return pointer to an empty list
*/
double_list* create_list();

/*************************************************
precondition: l is not NULL - checked with assertion
return whether list pointed to by l is empty
*/
int is_empty (const double_list* dl);

/*************************************************
precondition: l is not NULL - checked with assertion
return number of elements in the list
*/

int size (const double_list* dl);

/**************************************************
precondition: l is not NULL - checked with assertion
postcondition: item is at the end of *l
**************************************************/
void append (double_list* dl, void* item);

/**************************************************
precondition: l is not NULL - checked with assertion
postcondition: item is at the beginning of *l
**************************************************/
void prepend (double_list* dl, void* item);

/****************************************************
precondition: l is not NULL - checked with assertion
precondition: 0 <= index <= size of list
returns false if location is not valid - true ow
postcondition: item is at location in *l
*/
int insert (double_list* dl, void* item, int index);

/******************************************************
precondition: l is not NULL - checked with assertion
precondition: 0 <= index < size of list
returns false if index is not valid - true ow
postcondition: item at index in *l has been removed
*/
int remove_from_list (double_list* dl, int index);

/*****************************************************
precondition: l is not NULL - checked with assertion
precondition:  0 <= index < size of list
return element at index position of list - NULL if index
is not valid
****************************************************/
void* get (const double_list* dl, int index);

/*****************************************************
precondition: l is not NULL - checked with assertion
precondition:  0 <= index < size of list
return true if index is valid - false otherwise
postcondition: item is at index location in list
***************************************************/
int set (double_list* dl, void* item, int location);

/*************************************************
precondition: l is NULL - checked with assertion
postcondition: all components to the list have been
deallocated
*/
void delete_list (double_list* dl);

#endif

