
#include "MysteryShopMap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
#define MAX_ITEM 100
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef struct {
    KeyType key;
    int value; 
} MapEntry;

typedef struct {
    MapEntry data[MAX_ITEM];
    int count;
} MysteryShopMap;
/*


/* Cek apakah key ada di map. Return true jika ada, false jika tidak. */
bool EXISTS(const MysteryShopMap *M, const char *key) {
  for (int i = 0; i < M->count; i++) {
    if (!strcmp(key, M->data[i].key))
      return true;
  }
  return false;
}

/* Inisialisasi map kosong. Parameter: M = map yang akan diinisialisasi. */
void CREATE_MAP(MysteryShopMap *M) {
  M->count = 0;
}

/* Tambah/update pasangan key-value. Jika key sudah ada, value diperbarui. */
bool SET_ITEM(MysteryShopMap *M, const char *key, int value) {
  if (!EXISTS(M, key)) {
    strcpy(M->data[M->count].key, key);
    M->data[M->count].value = value;
    M->count++;
    return false;
  }

  int index = 0;
  while (strcmp(key, M->data[index].key)) {
      index++;
  }
  M->data[index].value = value;
  return true;
}

/* Ambil value dari key. Return true jika key ditemukan, false jika tidak. */
bool FIND_ITEM(const MysteryShopMap *M, const char *key, int *value) {
  if (!EXISTS(M, key)) return false;
  int index =0 ;
  while (strcmp(key, M->data[index].key)) {
      index++;
  }

  *value = M->data[index].value;
  return true;
}

/* Hapus key jika ada. Return true jika berhasil dihapus, false jika tidak ditemukan. */
bool UNSET_ITEM(MysteryShopMap *M, const char *key) {
  if (!EXISTS(M, key)) {
    return false;
  }
  int index = 0;
  while (strcmp(key, M->data[index].key)) {
      index++;
  }
  for (int i = index; i < M->count - 1; i++) {
    M->data[i] = M->data[i + 1]; 
  }
  M->count--;
  return true;
}

/* Jumlah key aktif saat ini. */
int SIZE(const MysteryShopMap *M) { return M->count; }

/* Mengembalikan jumlah total stok semua barang di dalam map. */
int TOTAL_STOCK(const MysteryShopMap *M) {
  int total = 0;
  for (int i = 0; i < SIZE(M); i++) {
    total += M->data[i].value;
  }
  return total;
}

/* Mencetak seluruh isi map dalam format:
   key value
   urut sesuai urutan penyimpanan (indeks array dari 0..count-1). */
void PRINT_MAP(const MysteryShopMap *M) {
  for (int i = 0; i < SIZE(M); i++) {
    printf("%s %d\n", M->data[i].key, M->data[i].value);
  }
}
