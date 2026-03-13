/* Template code programming karena malas */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fuck you fungsi
// bisa aja buat fungsi dari A -> B -> C ya gitulah malas
int main(int argc, char**argv) {
  float T;
  char Y;
  int N;
  scanf("%f %c %d", &T, &Y, &N);
 
  while(N--) {
    char perintah; float arg;
    scanf(" %c", &perintah);
    switch (perintah) {
      case 'C':
        if (Y == 'K') {
          T = T - 273.15; 
        }
        if (Y == 'F') {
          T = (T - 32) * 5/9;
        }
        Y = 'C';
        break;
      case 'K':
        if (Y == 'C') {
          T = T + 273.15; 
        }
        if (Y == 'F') {
          T = (T - 32) * 5/9 + 273.15;
        }
        Y = 'K';
        break;
      case 'F':
        if (Y == 'C') {
          T = T * 9/5 + 32; 
        }
        if (Y == 'K') {
          T = (T - 273.15) * 9/5 + 32;
        }
        Y = 'F';
        break;
      case 'A':
        scanf("%f", &arg);
        T += arg;
        break;
      case 'S':
        scanf("%f", &arg);
        T -= arg;
        break;
    }
  }

  printf("%.2f %c\n", T, Y);

  return 0;
}
