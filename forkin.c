#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(){
  srand(time(NULL));
  printf("Hi! I am the parent!\n");
  int f = fork();
  fork();

  if(!f){
    printf("\tHi! I am a child with pid: %d\n", getpid());
    int r = (rand() % 20) + 5;
    sleep(r);
    printf("\t I just slept, that was a good nap!\n");
  }else{
    
  }


}
