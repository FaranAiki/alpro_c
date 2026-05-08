
#include "DoroOrangeSet.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #define TEST

/*
#define MAX_ORANGE 100

typedef struct {
    int data[MAX_ORANGE];
    int count;
} DoroOrangeSet;
*/


/* Jumlah total diameter semua orange di set. */
int TOTAL_ENERGY(const DoroOrangeSet *S) {
  int t = 0;
  for (int i = 0; i < S->count; i++) {
    t += S->data[i];
  }
  return t;
}

// qsort wleee
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Inisialisasi set kosong. Parameter: S = set yang akan diinisialisasi. */
void CREATE_SET(DoroOrangeSet *S) {
  S->count = 0;
}

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool ADD_ORANGE(DoroOrangeSet *S, int x) {
  if (IS_MEMBER(S, x) || S->count == MAX_ORANGE) {
    return false;
  }

  S->data[S->count] = x;
  S->count++;
  return true;
}

/* Hapus x jika ada. Return true jika elemen ditemukan dan dihapus. */
bool REMOVE_ORANGE(DoroOrangeSet *S, int x) {
  if (!IS_MEMBER(S, x)) {
    return false;
  }

  int index = 0;
  while (S->data[index] != x) {
    index++;
  }

  for (int i = index; i < S->count - 1; i++) {
    S->data[i] = S->data[i + 1];
  }

  S->count--;
  return true;
}

/* Cek apakah x anggota set. Return true jika ada, false jika tidak. */
bool IS_MEMBER(const DoroOrangeSet *S, int x) {
  for (int i = 0; i < S->count; i++) {
    if (S->data[i] == x) return true;
  }
  return false;
}

/* Jumlah elemen unik saat ini. */
int CARDINALITY(const DoroOrangeSet *S) { return S->count; }

/* "output": cetak isi set dengan format {a, b, c}; jika kosong cetak "{}". */
void PRINT_SET(const DoroOrangeSet *S) {
  if (S->count == 0) {
    printf("{}\n");
    return;
  }
  qsort(S->data, S->count, sizeof(S->data[0]), comp);
  putchar('{');
  printf("%d", S->data[0]);
  for (int i = 1; i < S->count; i++) {
    printf(", %d", S->data[i]);
  }

  putchar('}');
  putchar('\n');
}


#ifdef TEST
int main() {
    DoroOrangeSet S;
    CREATE_SET(&S);

    char cmd[32];
    int x;

    while (scanf("%31s", cmd) != EOF) {
      if (strcmp(cmd, "ADD") == 0) {
        scanf("%d", &x);
        ADD_ORANGE(&S, x);
      } else if (strcmp(cmd, "REMOVE") == 0) {
        scanf("%d", &x);
        REMOVE_ORANGE(&S, x);
      } else if (strcmp(cmd, "CHECK") == 0) {
        scanf("%d", &x);
        printf("%s\n", IS_MEMBER(&S, x) ? "YES" : "NO");
      } else if (strcmp(cmd, "COUNT") == 0) {
        printf("%d\n", CARDINALITY(&S));
      } else if (strcmp(cmd, "PRINT") == 0) {
        // "output"
        PRINT_SET(&S);
      } else if (strcmp(cmd, "TOTAL") == 0) {
        // "output"
        printf("%d\n", TOTAL_ENERGY(&S));
      }
    }

    return 0;
}
#endif 
