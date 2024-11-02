#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of process : \n");
  scanf("%d", &n);
  int bt[n], wt[n], tat[n], p[n];
  printf("Enter the burst time for %d processes\n", n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &bt[i]);
    p[i] = i;
  }
  
  //Calculate the waithing time.
  
  
  int temp;
  for (int i = 1;i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (bt[i] > bt[j] ){
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  wt[1] = 0;
  for (int i =2; i <= n; i++) {
    wt[i] = wt[i-1]+bt[i-1];
  }

  for (int i =1; i <= n; i++) {
    tat[i] = bt[i]+wt[i];
  }

  printf("ProcessId\tBurstTime\tWaiting-Time\tTAT\n");
  for (int i = 1; i <= n; i++) {
    printf("Process%d\t\t%d\t\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }

  return 0;
}
