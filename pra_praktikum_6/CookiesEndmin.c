#include "CookiesEndmin.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort wleee
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Inisialisasi set kosong. Parameter: S = set yang akan diinisialisasi. */
void CREATE_SET(CookiesEndmin *S) {
  S->count = 0;
}

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool INSERT(CookiesEndmin *S, int x) {
  if (IS_MEMBER(S, x) || S->count == MAX_COOKIES) {
    return false;
  }

  S->data[S->count] = x;
  S->count++;
  return true;
}

/* Hapus x jika ada. Return true jika elemen ditemukan dan dihapus. */
bool REMOVE(CookiesEndmin *S, int x) {
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
bool IS_MEMBER(const CookiesEndmin *S, int x) {
  for (int i = 0; i < S->count; i++) {
    if (S->data[i] == x) return true;
  }
  return false;
}

/* Jumlah elemen unik saat ini. */
int CARDINALITY(const CookiesEndmin *S) { return S->count; }

/* "output": cetak isi set dengan format {a, b, c}; jika kosong cetak "{}". */
void PRINT_SET(const CookiesEndmin *S) {
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

/*
int main() {
    CookiesEndmin S;
    CREATE_SET(&S);

    char cmd[32];
    int x;

    while (scanf("%31s", cmd) != EOF) {
      if (strcmp(cmd, "INSERT") == 0) {
        scanf("%d", &x);
        INSERT(&S, x);
      } else if (strcmp(cmd, "REMOVE") == 0) {
        scanf("%d", &x);
        REMOVE(&S, x);
      } else if (strcmp(cmd, "ISMEMBER") == 0) {
        scanf("%d", &x);
        printf("%s\n", IS_MEMBER(&S, x) ? "YES" : "NO");
      } else if (strcmp(cmd, "CARDINALITY") == 0) {
        printf("%d\n", CARDINALITY(&S));
      } else if (strcmp(cmd, "PRINT") == 0) {
        // "output"
        PRINT_SET(&S);
      }
    }

    return 0;
  }*/ 
