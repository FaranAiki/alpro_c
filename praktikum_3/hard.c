/* Template code programming karena malas */
// soal hama
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long a[1024 * 1024];
unsigned long long pool[100000];
unsigned long long pool_max = 0;

int compare(const void *a, const void *b) {
  return *(unsigned long long*)a > *(unsigned long long*)b;
}

int checkdigit(unsigned long long n) {
  int count = 0;
  while (n) {
    n /= 10;
    count++;
  }
  return count;
}

int main(int argc, char**argv) {
  int N; int terakhir = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%ull", &a[i]);
  }

  // tinjau dari digit dulu boy
  // A maks 10^9, maka tinjau sampe sepuluh
  for (int dig = 20; dig >= 1; dig--) {
    pool_max = 0;
    for (int i = 0; i < N; i++) {
      if (checkdigit(a[i]) == dig) {
        pool[pool_max] = a[i];
        pool_max++;
      }
    }
    // baru print sekarang 
    // sort dulu 
    qsort(pool, pool_max, sizeof(unsigned long long), compare);
    for (int i = 0; i < pool_max; i++) {
      terakhir++;
      if (terakhir == N) {
        printf("%d", pool[i]);
      } else printf("%d ", pool[i]); 
    }
  }
  printf("\n");

  return 0;
}
