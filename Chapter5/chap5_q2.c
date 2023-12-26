#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int sz;
  int fp = open("q5_2.txt", O_WRONLY | O_CREAT);
  pid_t p = fork();
  if(p<0){
    printf("Fail to fork");
    return 1;
  }else if(p == 0){
    char* s_child = "child write\n";
    sz = write(fp, s_child, strlen(s_child));
    printf("child %d write %d\n", fp, sz);
  }else {
    char* s_parent = "parent write\n";
    sz = write(fp, s_parent, strlen(s_parent));
    printf("parent %d write %d\n", fp, sz);
  }
  
  close(fp);
  return 0;
}
