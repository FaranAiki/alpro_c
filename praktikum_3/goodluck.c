/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024 * 1024 * 4];

int main(int argc, char**argv) {
  int N; long long K;
  scanf("%d %lld", &N, &K);

  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

    int idx = 0;
    int current = K % 10001;
    do  {
      idx = a[idx];
    } while(current--);
    printf("%d", idx);

  for (int i = 1; i < N; i++) {
    int idx = i;
    int current = K % 10001;
    do  {
      idx = a[idx];
    }while(current--);
    printf(" %d", idx);
  }
  printf("\n");

  return 0;
}
