#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(){
  int ppid = getpid();
  srand(time(NULL));
  printf("Hi! I am the parent! My id is: %d\n", getpid());
  int process = fork();
  if (getpid() == ppid){
         process = fork();
    }
  if(!(process)){
      printf("\tHi! I am a child with pid: %d\n", getpid());
      int r = rand() % 20 + 5;
      sleep(r);
      printf("\t I just slept, that was a good nap!\n");
      exit(r);
  }else{
    int status;
    int child_id = wait(&status);
    printf("My child %d has just slept for %d seconds!\n", child_id, WEXITSTATUS(status));
    printf("Parent is done.\n");
  }
}
