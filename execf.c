#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  printf("Before execvp()\n");
  int status = execvp("ls", (char *const[]){"ls","-l", NULL});
  if (status == -1) {

    printf("Terminated Incorrectly\n");
  }
  printf("This will not be printed\n");
  return 0;
}
