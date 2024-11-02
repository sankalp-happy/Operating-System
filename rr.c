#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of procces\n");
  scanf("%d", &n);
  int bt[n], wt[n], tat[n], rem_bt[n];
  printf("%d process\n", n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &bt[i]);
  }
  int qt;
  printf("Enter the time quantum\n");
  scanf("%d", &qt);

  for (int i = 1; i <= n; i++) {
    rem_bt[i] = bt[i];
  }
  int time = 0;
  while(1) {
    int done = 1;
    for (int i = 1; i <= n; i++) {
      if (rem_bt[i] > 0) {
        done = 0;
        if (rem_bt[i] > qt) {
          time += qt;
          rem_bt[i] -= qt;
        } else {
          time += rem_bt[i];
          wt[i] = time - bt[i];
          rem_bt[i] = 0;
        }
      }

    }

    if(done == 1) break;

  }

  for (int i= 1; i <= n; i++) {
    tat[i] = wt[i] + bt[i];
    printf("ProcessId%d\t%d\t%d\t%d\n", i, bt[i], wt[i], tat[i]);
  }
  return 0;
}
