/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char sandi[1024 * 1024];


int main(int argc, char**argv) {
  int N, x, y;
  char A, B;
  scanf("%d %d %d %c %c", &x, &y, &N, &A, &B);
  
  memset(sandi, '@', N);

  int aa = x - 1;
  int bb = y - 1;

  while (bb < N) {
    sandi[bb] = B;
    bb += y;
  }

  while (aa < N) {
    sandi[aa] = A;
    aa += x;
  }

  sandi[N] = 0;
  printf("%s\n", sandi);

  return 0;
}
