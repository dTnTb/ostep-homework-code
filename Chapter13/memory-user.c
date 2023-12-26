#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Invalid argument\n");
    return 1; 
  }

  int cnt_MB = atoi(argv[1]);
  printf("create %d MB memory\n", cnt_MB); 
  int* a_test = (int*)malloc(cnt_MB * 1024 * 1024); 
  for(int i = 0; i<cnt_MB*1024*1024/sizeof(int); i++){
    a_test[i] = 1; 
    //printf("%p\n", &(a_test[i]));
  }   
  printf("pid = %d\n", getpid()); 
  printf("Create End\b");
  sleep(10);
  free(a_test); 
  return 0;
}
