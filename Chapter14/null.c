#include <stdio.h>

void main() {
  // Create a pointer to a integer  
  int i = 0; 
  int *p = &i;
  // Set pointer to null
  p = NULL;
  // Dereference/Redirect pointer
  *p = 0;
}
