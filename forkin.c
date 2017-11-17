#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(){
  printf("Hi! I am the parent! My id is: %d\n", getpid());

  int f = fork();
  // if the process is the parent, fork again
  if (f){
    f = fork();
  }

  // we used getpid() as the seed for srand() so each process generates different random numbers
  srand(getpid());

  if(!f){
    int pid = getpid();
    printf("\tHi! I am a child with pid: %d\n", pid);
    int r = rand() % 16 + 5;
    sleep(r);
    printf("\tI (pid %d) just slept, that was a good nap!\n", pid);

    // passing sleep time to exit() so parent can access it with WEXITSTATUS()
    exit(r);
  }
  else{
    int status;
    int child_id = wait(&status);
    printf("My child %d has just slept for %d seconds!\n", child_id, WEXITSTATUS(status));
    printf("Parent is done.\n");
  }
}
