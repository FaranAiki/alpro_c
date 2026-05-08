/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024 * 1024 * 4];

int main(int argc, char**argv) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  int M;
  scanf("%d", &M);

  long long total_geser = 0; // tanda L negatif, tanda R positif

  while (M--) {
    char tipe; long long brp;
    scanf(" %c %lld", &tipe, &brp);
    if (tipe == 'L')
      total_geser += brp;
    else
      total_geser -= brp;
  }

  printf("%d", a[(3*N + 0 + total_geser) % N]);
  for (int i = 1; i < N; i++) {
    printf(" %d", a[(3*N + i + total_geser) % N]);
  }
  printf("\n");

  return 0;
}
