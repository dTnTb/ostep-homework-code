#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int sz;
  pid_t p = fork();
  if(p<0){
    printf("Fail to fork");
    return 1;
  }else if(p == 0){
    close(STDOUT_FILENO);
    printf("child write\n");
  }else {
    printf("parent write\n");
  }
  
  return 0;
}
