/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024 * 1024];

int main(int argc, char**argv) {
  int N; int A;
  scanf("%d", &N);
  A = N;
  while (N--)
    scanf("%d", &a[N]);

  printf("%d", a[0]);
  for (int i = 1; i < A; i++) 
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}
