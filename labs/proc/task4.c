#include <sys/time.h> 
#include <stdio.h>

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end);
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end);

int main() { 
  int i;
  struct timeval startTime, currentTime; 
  gettimeofday(&startTime, NULL);

  sleep(1);

  gettimeofday(&currentTime,NULL); 
  printf("Difference in milli-seconds %d\n",
    getDifferenceInMilliSeconds(startTime, currentTime));
  printf("Difference  in  micro-seconds %d\n",
    getDifferenceInMicroSeconds(startTime, currentTime));
}

long int getDifferenceInMilliSeconds(struct timeval start, struct timeval end) {
  int seconds = end.tv_sec - start.tv_sec;
  int useconds = end.tv_usec - start.tv_usec;
  int mtime = (seconds * 1000 + useconds / 1000.0); return mtime;
}
long int getDifferenceInMicroSeconds(struct timeval start, struct timeval end) {
  int seconds = end.tv_sec - start.tv_sec; 
  int useconds = end.tv_usec - start.tv_usec; 
  int mtime = (seconds * 1000000 + useconds); 
  return mtime;
}
