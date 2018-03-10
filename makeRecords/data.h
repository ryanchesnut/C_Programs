// Ryan Chesnut
// linux_c
// assignment 8
#ifndef _DATA_H
#define _DATA_H

#define NAMESIZE 15

typedef struct
{
  char name[NAMESIZE];
  float price; 
  int count;
} data;

data* create_data (char* n, float p, int c);

void display_data (data* d);

#endif

