#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("Before execvp()\n");
  pid_t p = fork();
  if (p == 0) {
    printf("Child Process\n");
    int status = execvp("ls", (char *const[]){"ls","-l", NULL});
    if (status == -1) {
      printf("Terminated Incorrectly\n");
      exit(1);
    }
  }
  else {
    printf("Parent process\n");
    wait(NULL);
    printf("Done\n");
  }
  return 0;
}
