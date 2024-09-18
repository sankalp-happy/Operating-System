#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  printf("Before execvp()\n");
  pid_t p = fork();
  if (p == 0) {
    printf("Child Process\n");
    int status = execvp("ls", (char *const[]){"ls","-l", NULL});
    if (status == -1) {
      printf("Terminated Incorrectly\n");
    }
  }
  else {

   printf("Done\n");
  }
  return 0;
}
