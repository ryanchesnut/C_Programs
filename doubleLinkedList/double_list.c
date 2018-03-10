//Ryan Chesnut
//assignment 3
//linux and c

#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


node* create_node (void* item){
  node* n = malloc (sizeof (node));
  n -> item = item;
  n -> next = NULL;
  n -> prev = NULL;
  return n;
}

double_list* create_list(){
  double_list* dl = malloc (sizeof(double_list));
  dl -> front = NULL;
  dl -> rear = NULL;
  dl -> size = 0;
  return dl;
}

int is_empty (const double_list* dl){
  assert (dl != NULL);
  return dl -> size == 0;
}

int size (const double_list* dl){
  assert (dl != NULL);
  return dl -> size;

}

void append (double_list* dl, void* item){
 assert (dl != NULL);
  node* n = create_node (item);
  if (is_empty (dl))
  {
   dl -> front = n;
   dl -> rear = n;
  }
  else
  {
    dl -> rear -> next = n;
    n -> prev = dl -> rear;
    n -> next = NULL;
    dl -> rear = n;
  }
  dl -> size++;
}

void prepend (double_list* dl, void* item){
   assert (dl != NULL);
  node* n = create_node (item);
  if (is_empty (dl))
  {
    dl -> front = n;
    dl -> rear = n;
  }
  else
  {
    n -> next = dl -> front;
    n -> prev = NULL;
    dl -> front = n;
  }
  dl -> size++;
}

int insert (double_list* dl, void* item, int index){
 assert (dl != NULL);
  int result = index >= 0 && index <= size(dl);
  if (result)
  {
    if (index == 0)
	prepend (dl, item);
    else if (index == size(dl))
      append (dl, item);
    else
    {
      node* temp = dl -> front;
      for (int i = 0; i < index - 1; i++)
	     temp = temp -> next;
      
      node* n = create_node (item);
     
      n -> next = temp -> next;
      n -> prev = temp;
      temp -> next = n;
      dl -> size++;
    }
  }
  return result;
}

int remove_from_list (double_list* dl, int index){
 assert (dl != NULL);
  int result = index >= 0 && index < size(dl);
  if (result)
  {
    node* n;
    if (index == 0)
    {
      n = dl -> front;
      dl -> front = n -> next;
      n -> prev = NULL;
      if (dl -> front == NULL)
	  dl -> rear = NULL;
    }
    else
    {
      node* temp = dl -> front;
      for (int i = 0; i < index - 1; i++)
   	    temp = temp -> next;
      n = temp -> next;
       
      temp -> next = n -> next;
      temp -> prev = n -> prev;
      
      if (temp -> next == NULL){
	   dl -> rear = temp;
	  
	   }
    }
    free (n);
    dl -> size--;
  }
  return result;
}

void* get (const double_list* dl, int index){
 assert (dl != NULL);
 void* result = NULL;
 if (index >= 0 && index < size(dl))
 {
   node* temp = dl -> front;
   for (int i = 0; i < index; i++)
     temp = temp -> next;
   result = temp -> item;
 }
 return result;
}

int set (double_list* dl, void* item, int index){
 assert (dl != NULL);
 int result = index >= 0 && index < size(dl);
 if (result)
 {
   node* temp = dl -> front;
   for (int i = 0; i < index; i++)
     temp = temp -> next;
   temp -> item = item;
 }
 return result;
}

void delete_list (double_list* dl){
   assert (dl != NULL);
  node* n = dl -> front;
  for (int i = 0; i < size(dl); i++)
  {
    node* temp = n;
    n = n -> next;
    free (temp);
  }
  free (dl);
}



