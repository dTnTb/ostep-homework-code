#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
int main()
{
  struct timeval tv_cur;
  struct timeval tv_pre;
  int cnt = 10000;
  int err;
  char cin; 
  gettimeofday(&tv_pre, NULL);
  for(int i = 0; i<cnt; i++){
    err = read(STDIN_FILENO, &cin, 0);
    if(err < 0){
      printf("Fail to read 0\n");
      return 1; 
    } 
  }
  gettimeofday(&tv_cur, NULL);
  unsigned long t_pre_ms = tv_pre.tv_sec * 1000 + tv_pre.tv_usec; 
  unsigned long t_cur_ms = tv_cur.tv_sec * 1000 + tv_cur.tv_usec; 
  double t_exec = (t_cur_ms - t_pre_ms + 0.0)/cnt; 
  printf("exec time = %.4f\n", t_exec);
  return 0;
}

