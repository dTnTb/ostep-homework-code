#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  //execl("/usr/bin/", "wc", "t1.c", "|", "echo", NULL);
  execlp("wc", "wc", "t1.c", NULL);
  return 0; 
}
