#ifndef COOKIESENDMIN_H
#define COOKIESENDMIN_H

#include <stdbool.h>

#define MAX_COOKIES 100

/* ADT set integer unik dengan kapasitas tetap. */
typedef struct {
    int data[MAX_COOKIES];
    int count;
  } CookiesEndmin;

/* Inisialisasi set kosong. Parameter: S = set yang akan diinisialisasi. */
  void CREATE_SET(CookiesEndmin *S);

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
  bool INSERT(CookiesEndmin *S, int x);

/* Hapus x jika ada. Return true jika elemen ditemukan dan dihapus. */
  bool REMOVE(CookiesEndmin *S, int x);

/* Cek apakah x anggota set. Return true jika ada, false jika tidak. */
  bool IS_MEMBER(const CookiesEndmin *S, int x);

/* Jumlah elemen unik saat ini. */
  int CARDINALITY(const CookiesEndmin *S);

/* "output": cetak isi set dengan format {a, b, c}; jika kosong cetak "{}". */
  void PRINT_SET(const CookiesEndmin *S);

#endif
