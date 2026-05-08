#ifndef DOROORANGESET_H
#define DOROORANGESET_H

#include <stdbool.h>

#define MAX_ORANGE 100

/* ADT set integer untuk menyimpan diameter orange unik. */
typedef struct {
    int data[MAX_ORANGE];
    int count;
} DoroOrangeSet;

/* Inisialisasi set kosong. */
void CREATE_SET(DoroOrangeSet *S);

/* Tambah x jika belum ada. Return true jika berhasil, false jika duplikat/penuh. */
bool ADD_ORANGE(DoroOrangeSet *S, int x);

/* Hapus x jika ada. Return true jika berhasil dihapus. */
bool REMOVE_ORANGE(DoroOrangeSet *S, int x);

/* Cek apakah x anggota set. */
bool IS_MEMBER(const DoroOrangeSet *S, int x);

/* Jumlah elemen unik pada set. */
int CARDINALITY(const DoroOrangeSet *S);

/* Jumlah total diameter semua orange di set. */
int TOTAL_ENERGY(const DoroOrangeSet *S);

/* "output": cetak set dengan format {a, b, c}; jika kosong cetak "{}". */
void PRINT_SET(const DoroOrangeSet *S);

#endif
