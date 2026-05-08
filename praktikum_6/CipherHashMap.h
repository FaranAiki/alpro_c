#ifndef CIPHERHASHMAP_H
#define CIPHERHASHMAP_H

#include <stdbool.h>

#define TABLE_SIZE 101
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef enum {
    SLOT_EMPTY,   /* tidak pernah diisi */
    SLOT_OCCUPIED,/* sedang terisi entry valid */
    SLOT_DELETED  /* pernah terisi, sekarang dihapus */
} SlotStatus;

typedef struct {
    KeyType key;
    int value;
    SlotStatus status;
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
    int count; /* jumlah entry berstatus SLOT_OCCUPIED */
} CipherHashMap;

/* Inisialisasi map kosong. Semua slot berstatus SLOT_EMPTY. */
void CREATE_HASHMAP(CipherHashMap *M);

/* Fungsi hash sederhana: jumlah kode ASCII karakter key, kemudian mod TABLE_SIZE. */
int HASH_FUNCTION(const char *key);

/* Menambahkan atau mengubah pasangan (key, value).
   - Jika key sudah ada, update value.
   - Jika key belum ada, simpan pada slot kosong (EMPTY atau DELETED) pertama yang ditemukan.
   Return true jika berhasil, false jika tabel penuh. */
bool SET_SPELL(CipherHashMap *M, const char *key, int value);

/* Menghapus entry dengan key tertentu.
   - Jika key ditemukan, ubah status slot menjadi SLOT_DELETED dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool UNSET_SPELL(CipherHashMap *M, const char *key);

/* Mencari value berdasarkan key.
   - Jika ditemukan, tulis ke *value dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool FIND_SPELL(const CipherHashMap *M, const char *key, int *value);

/* Mencetak semua entry berstatus SLOT_OCCUPIED:
   key value
   Satu entry per baris. Urutan tidak harus terurut. */
void PRINT_HASHMAP(const CipherHashMap *M);

#endif
