/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024 * 1024];

int main(int argc, char**argv) {
  int N; int X; int A; int ada = 0;
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    if (a[i] == X) ada = 1;
  }
 
  if (ada) printf("%d ", X);
  printf("%d", a[0]);
  for (int i = 1; i < N; i++)
    printf(" %d", a[i]); 
  printf("\n");

  return 0;
}
