/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int checkangkaaneh(long n) {
  long count = 0;
  int awal = n;
  while (n) {
    count += factorial[n % 10];
    n /= 10;
  }

  if (awal == count) return 1;
  return 0;
}

int main(int argc, char**argv) {
  long N, n;
  scanf("%ld", &N);

  while(N--) {
    scanf("%ld", &n);
    if (checkangkaaneh(n)) printf("BAHAYA\n");
    else printf("AMAN\n");
  }

  return 0;
}
