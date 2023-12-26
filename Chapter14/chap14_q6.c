#include <stdio.h>
#include <stdlib.h>

void main() {

  int n = 100;
  // Create a pointer to a integer  
  int *p = (int*)malloc(n*sizeof(int));
  
  for(int i = 0; i<n; i++)
    *(p+i) = 0;

  free(p);
}
