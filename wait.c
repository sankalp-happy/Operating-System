#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  printf("Begin\n");
  pid_t p = fork();
  if (p < 0) {
    printf("fork failed\n");
  } else if (p == 0) {
    printf("Child Process\n");
  } else {
    printf("Parent Process\n");
    wait(NULL);
    printf("Child Terminates\n");
  }
  printf("Done\n");
  return 0;
}
