// Ryan Chesnut
// linux_c
// assignment 8
#include "data.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

data* create_data (char* n, float p, int c)
{
  assert (n != NULL);
  data* d = malloc (sizeof(data));
  if (d != NULL)
  {
    strncpy (d -> name, n, NAMESIZE - 1);
    d -> price = p; 
    d -> count = c;
  }
  return d;
}

void display_data (data* d)
{
  assert (d != NULL);
  float total = (d -> price) * (d -> count); 
  printf ("%s\t       %.02f X \t %d = %.02f \n", d -> name, d -> price, d -> count, total);
}


