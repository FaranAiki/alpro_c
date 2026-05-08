
#include "MysteryJournalSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#define MAX_PAGE 200

typedef struct {
    int data[MAX_PAGE];
    int count;
} MysteryJournalSet;
*/


// qsort wleee
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Inisialisasi set kosong. Parameter: S = set yang akan diinisialisasi. */
void CREATE_SET(MysteryJournalSet *S) {
  S->count = 0;
}

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool INSERT_PAGE(MysteryJournalSet *S, int x) {
  if (IS_MEMBER(S, x) || S->count == MAX_PAGE) {
    return false;
  }

  S->data[S->count] = x;
  S->count++;
  return true;
}

/* Hapus x jika ada. Return true jika elemen ditemukan dan dihapus. */
bool DELETE_PAGE(MysteryJournalSet *S, int x) {
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
bool IS_MEMBER(const MysteryJournalSet *S, int x) {
  for (int i = 0; i < S->count; i++) {
    if (S->data[i] == x) return true;
  }
  return false;
}

/* Jumlah elemen unik saat ini. */
int CARDINALITY(const MysteryJournalSet *S) { return S->count; }

/* "output": cetak isi set dengan format {a, b, c}; jika kosong cetak "{}". */
void PRINT_SET(const MysteryJournalSet *S) {
  if (S->count == 0) {
    printf("{}");
    return;
  }
  qsort(S->data, S->count, sizeof(S->data[0]), comp);
  putchar('{');
  printf("%d", S->data[0]);
  for (int i = 1; i < S->count; i++) {
    printf(", %d", S->data[i]);
  }

  putchar('}');
}

/* Mengembalikan true jika set kosong. */
bool IS_EMPTY(const MysteryJournalSet *S) {
  return (S->count == 0);
}

/* Menghasilkan union dari S1 dan S2: semua elemen yang ada di S1 atau S2 atau keduanya. */
MysteryJournalSet UNION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2) {
  MysteryJournalSet t;
  CREATE_SET(&t);
  for (int i = 0; i < S1->count; i++ ) {
    INSERT_PAGE(&t, S1->data[i]);
  }
  for (int i = 0; i < S2->count; i++ ) {
    INSERT_PAGE(&t, S2->data[i]);
  }
  return t;
};

/* Menghasilkan intersection dari S1 dan S2: hanya elemen yang ada di kedua set. */
MysteryJournalSet INTERSECTION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2) {
  MysteryJournalSet t;
  CREATE_SET(&t);
  for (int i = 0; i < S1->count; i++) {
    if (IS_MEMBER(S2, S1->data[i])) {
      INSERT_PAGE(&t, S1->data[i]);
    }
  }
  return t;
}

/* Menghasilkan difference S1 - S2: elemen yang ada di S1 tetapi tidak di S2. */
MysteryJournalSet DIFFERENCE_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2) {
  MysteryJournalSet t;
  CREATE_SET(&t);
  for (int i = 0; i < S1->count; i++) {
    if (!IS_MEMBER(S2, S1->data[i])) {
      INSERT_PAGE(&t, S1->data[i]);
    }
  }
  return t;
}

