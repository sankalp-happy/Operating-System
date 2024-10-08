#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  printf("Before fork()\n");
  pid_t p = fork();
  if (p < 0) {
    printf("fork failed\n");
  }
  else if (p == 0) {
    printf("My id is : %d\n", getpid());
    printf("My parents id is : %d\n", getppid());
  } else {
    printf("My id is : %d\n", getpid());
    printf("My parents id is : %d\n", p);
  }
  printf("Done\n");
  return 0;
}
