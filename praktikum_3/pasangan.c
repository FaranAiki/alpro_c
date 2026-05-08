/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024 * 1024];

int min(int a, int b) {
  if (b > a) return a;
  return b;
} 

int main(int argc, char**argv) {
  int N; int A;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]); 

  long long total = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      total += min(a[i], a[j]);

  printf("%ld\n", total);
  return 0;
}
