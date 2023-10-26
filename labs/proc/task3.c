#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_PROCESSES 4

int main() {
  int i, status;
  pid_t pid;

  for (i=0;i < NUMBER_OF_PROCESSES; i++) {
    printf("Hello from the parent process\n"); 
    pid = fork();

    if(pid < 0) {
      printf("fork error\n"); 
    } else if(pid == 0) {
      sleep(1);
      printf("Hello from the child process with PID %d, and ID=%d\n", getpid(), i); return;
    }
  }
  waitpid(pid, &status, WUNTRACED); 
  printf("Bye from the parent \n");
  
}

