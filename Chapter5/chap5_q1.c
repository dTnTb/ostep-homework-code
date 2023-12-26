#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int i = 100;
  pid_t p = fork();
  if(p<0){
    printf("Fail to fork");
    return 1;
  }else if(p == 0){
    i = i + 100;
    printf("child i = %d\n", i );
  }else {
    i = i + 50;
    printf("parent i = %d\n", i );
  }
  return 0;
}
