#ifndef MYSTERYSHOPMAP_H
#define MYSTERYSHOPMAP_H

#include <stdbool.h>

#define MAX_ITEM 100
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef struct {
    KeyType key;
    int value; /* stok */
} MapEntry;

typedef struct {
    MapEntry data[MAX_ITEM];
    int count;
} MysteryShopMap;

/* Membuat map kosong. */
void CREATE_MAP(MysteryShopMap *M);

/* Mengembalikan true jika map kosong. */
bool IS_EMPTY(const MysteryShopMap *M);

/* Menambahkan pasangan (key, value) ke map.
   Jika key belum ada, tambahkan entry baru.
   Jika key sudah ada, update value dengan yang baru.
   Return true jika berhasil menambah entry baru atau mengupdate. */
bool SET_ITEM(MysteryShopMap *M, const char *key, int value);

/* Menghapus entry dengan key tertentu.
   Return true jika entry ditemukan dan dihapus, false jika tidak ada. */
bool UNSET_ITEM(MysteryShopMap *M, const char *key);

/* Mencari stok (value) berdasarkan key.
   Jika ditemukan, tulis stok ke *value dan return true.
   Jika tidak ditemukan, return false. */
bool FIND_ITEM(const MysteryShopMap *M, const char *key, int *value);

/* Mengembalikan jumlah total stok semua barang di dalam map. */
int TOTAL_STOCK(const MysteryShopMap *M);

/* Mencetak seluruh isi map dalam format:
   key value
   urut sesuai urutan penyimpanan (indeks array dari 0..count-1). */
void PRINT_MAP(const MysteryShopMap *M);

#endif
