#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
  struct timeval tv_cur;
  struct timeval tv_pre;
  gettimeofday(&tv_pre, NULL);
  int cnt = 0;
  while(1){ 
    gettimeofday(&tv_cur, NULL);
    unsigned long t_cur_ms = tv_cur.tv_sec*1000 + tv_cur.tv_usec;
    unsigned long t_pre_ms = tv_pre.tv_sec*1000 + tv_pre.tv_usec;
    if(t_cur_ms < t_pre_ms){
     printf("%lu - %lu\n", t_cur_ms, t_pre_ms);
     break; 
    }
    tv_pre = tv_cur;
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
