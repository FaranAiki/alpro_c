/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long countdigit(long n) {
  long count = 0;
  while (n) {
    count++;
    n /= 10;
  }
  return count;
}

long pangkatin(long n, long asli) {
  long count = 0;
  while (n) {
    asli *= 10;
    n /= 10;
  }
  return asli;
}

long hitungdigit(long n) {
  long count = 0;
  while (n) {
    count += n % 10;
    n /= 10;
  }
  return count;
}

long main(long argc, char**argv) {
  long N;
  scanf("%ld", &N);

  // printf("%d\n", countdigit(N));
  long operasi1 = pangkatin(N, hitungdigit(N)) + N; 
  long operasi2 = pangkatin(operasi1, countdigit(operasi1)) + operasi1;

  printf("%ld\n", operasi2);

  return 0;
}
