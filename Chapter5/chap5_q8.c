#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int pipefd[2];
  char buf;

  if (pipe(pipefd) == -1){
    printf("Fail to pipe");
    return 1;
  }

  pid_t p = fork();
  if(p<0){
    printf("Fail to fork");
    return 1;
  }else if(p == 0){
    // Child
    close(pipefd[1]);
    printf("child write\n");
    while(read(pipefd[0], &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);
    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS); 
   }else {
    wait(NULL);
    close(pipefd[0]);
    printf("parent write\n");
    char* s_test = "test pipe";
    write(pipefd[1], s_test , strlen(s_test));
    close(pipefd[1]);
    _exit(EXIT_SUCCESS); 
  }
}
