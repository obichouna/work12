#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(){
  int pids[2];
  int i;
  srand(time(NULL));
  printf("Hi! I am the parent!\n");

  for(i = 0; i < 2; i++){
    pids[i] = fork();
    if(!(pids[i]))){
      printf("\tHi! I am a child with pid: %d\n", getpid());
      int r = (rand() % 20) + 5;
      sleep(r);
      printf("\t I just slept, that was a good nap!\n");
      exit(0);
    }
  }
  
  int status;
  int pid;
  while(n

}
