#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main()
{
  int pipefd[2];
  char buf;

  // Create Pipe 
  if (pipe(pipefd) == -1){
    printf("Fail to pipe");
    return 1;
  }
  double d_t_sum_exec = 0;
  int n = 1000000;
  cpu_set_t set;
  CPU_ZERO(&set);
  CPU_SET(1, &set); 
  pid_t p = fork();
  pid_t real_pid = getpid();
  sched_setaffinity(real_pid, sizeof(set), &set);
  if(p<0){
    printf("Fail to fork");
    return 1;
  }

  for(int i = 0; i<n; i++) {
    if(p == 0){
      // Child
      if(read(pipefd[0], &buf, 1) > 0)
        write(pipefd[1], "1", 1);
    }else {
      if(i==0) write(pipefd[1], "1", 1);
      struct timespec ts_pre, ts_cur;
      clock_gettime(CLOCK_REALTIME, &ts_pre);
      // Parent
      if(read(pipefd[0], &buf, 1) > 0){
        write(pipefd[1], "1", 1);
      }
      clock_gettime(CLOCK_REALTIME, &ts_cur);
      double d_pre_ns = ts_pre.tv_sec*1e9 + ts_pre.tv_nsec;
      double d_cur_ns = ts_cur.tv_sec*1e9 + ts_cur.tv_nsec; 
      d_t_sum_exec += (d_cur_ns - d_pre_ns);  
    }
  }
  if( p > 0) printf("Context Switching time = %.0f\n", d_t_sum_exec/n); 
  return 0;
}
