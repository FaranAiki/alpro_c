#ifndef MYSTERYJOURNALSET_H
#define MYSTERYJOURNALSET_H

#include <stdbool.h>

#define MAX_PAGE 200

/* ADT Set of int dengan elemen unik, disimpan di array statik. */
typedef struct {
    int data[MAX_PAGE];
    int count;
} MysteryJournalSet;

/* Inisialisasi set kosong. */
void CREATE_SET(MysteryJournalSet *S);

/* Mengembalikan true jika set kosong. */
bool IS_EMPTY(const MysteryJournalSet *S);

/* Menambah elemen x ke dalam set (jika belum ada). Return true jika berhasil, false jika sudah ada atau penuh. */
bool INSERT_PAGE(MysteryJournalSet *S, int x);

/* Menghapus elemen x dari set (jika ada).
   Return true jika berhasil menghapus, false jika tidak ditemukan. */
bool DELETE_PAGE(MysteryJournalSet *S, int x);

/* Mengembalikan true jika x adalah anggota set. */
bool IS_MEMBER(const MysteryJournalSet *S, int x);

/* Mengembalikan banyaknya elemen di dalam set. */
int CARDINALITY(const MysteryJournalSet *S);

/* Menghasilkan union dari S1 dan S2: semua elemen yang ada di S1 atau S2 atau keduanya. */
MysteryJournalSet UNION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2);

/* Menghasilkan intersection dari S1 dan S2: hanya elemen yang ada di kedua set. */
MysteryJournalSet INTERSECTION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2);

/* Menghasilkan difference S1 - S2: elemen yang ada di S1 tetapi tidak di S2. */
MysteryJournalSet DIFFERENCE_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2);

/* Mencetak isi set dengan format {a, b, c}. Elemen harus dicetak dalam urutan menaik. Jika kosong, cetak "{}". */
void PRINT_SET(const MysteryJournalSet *S);

#endif    
