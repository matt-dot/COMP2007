#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_PROCESSES 10

int main(){
  int i;	
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    execl("/bin/ps", "ps", "-l", 0);
  }

  for (i = 0; i < NUMBER_OF_PROCESSES; i++) {
    pid = fork();
    if(pid < 0) {
      printf("Could not create process\n"); exit(1);
    } else if (pid == 0) {
      sleep(1);
      printf("Hello from the child process id=%d, pid=%d\n", i, getpid());
      exit(0);
    } else if (pid > 0) {
    //  printf("Hello from the parent process\n");
    }
  }

} 

