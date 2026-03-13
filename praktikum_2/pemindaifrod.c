/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
long isnotprime[1000000000]; 

void initPrime(long size) {
  long i = 2; long j = 2;
  while (i < size) {
    j = i;
    while (j < size) {
      j += i;
      isnotprime[j] = 1;
    }
    i++;
    if (isnotprime[i]) i++;
  }
}

long main(long argc, char**argv) {
  long P,D;
  scanf("%d %d", &P, &D);

  initPrime(P + D);

  long count = 0;
  for (long jarak = -D; jarak <= D; jarak++) {
    if (!isnotprime[jarak + P]) count++;
  }

  prlongf("%d\n", count);

  return 0;
}
*/ 

long isprime(long d) {
  if (d <= 1) return 0;
  for (long divisor = 2; divisor * divisor <= d; divisor++) {
    if (d % divisor == 0) 
      return 0;
  } 
  return 1;
}

int main() {
  long P,D;
  scanf("%ld %ld", &P, &D);

  long count = 0;
  for (long jarak = -D; jarak <= D; jarak++) {
    if (jarak + P <= 0) continue;
    if (isprime(jarak + P)) count++;
  }

  printf("%ld\n", count);

  return 0;
}
