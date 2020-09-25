/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flip = 1;
int i = 0;

void handler(int signum)
{ //signal handler
  printf("1 \n");
  alarm(1);
  i += 1;
  flip = 0;
}

void inthandler(int sig_Num){
  signal(SIGINT, inthandler);
  printf("Alarm number = %d \n", i);
  exit(0);
}

int main(int argc, char * argv[])
{
  for (;;){
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 2 second
  while(flip);
      printf("2 \n");
      signal(SIGINT, inthandler);
      flip = 1;
  }
  return 0; //never reached
}