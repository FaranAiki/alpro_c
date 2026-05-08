
#include "CipherHashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#define TABLE_SIZE 101 angka prima bung
#define MAX_KEY_LEN 32

typedef char KeyType[MAX_KEY_LEN];

typedef enum {
    SLOT_EMPTY,   
    SLOT_OCCUPIED,/
    SLOT_DELETED  /* pernah terisi, sekarang dihapus 
} SlotStatus;

typedef struct {
    KeyType key;
    int value;
    SlotStatus status;
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
    int count;  jumlah entry berstatus SLOT_OCCUPIED 
} CipherHashMap;
*/

// najisnyee
#define hash HASH_FUNCTION

/* Inisialisasi map kosong. Semua slot berstatus SLOT_EMPTY. */
void CREATE_HASHMAP(CipherHashMap *M) {
  M->count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    M->table[i].status = SLOT_EMPTY;
  }
}

/* Fungsi hash sederhana: jumlah kode ASCII karakter key, kemudian mod TABLE_SIZE. */
int HASH_FUNCTION(const char *key) {
  int tot = 0;
  for (int i = 0; i < strlen(key); i++) {
    tot += (unsigned char) key[i];
  }
  return tot % TABLE_SIZE;
}

/* Menambahkan atau mengubah pasangan (key, value).
   - Jika key sudah ada, update value.
   - Jika key belum ada, simpan pada slot kosong (EMPTY atau DELETED) pertama yang ditemukan.
   Return true jika berhasil, false jika tabel penuh. */
bool SET_SPELL(CipherHashMap *M, const char *key, int value) {

  // i am so fucking cooked harus nulis komen dawg kowokoaw
  // kalo occupied, 
  if (M->table[hash(key)].status == SLOT_OCCUPIED) {
    // berarti mereka sama, tinggal update
    if (!strcmp(key, M->table[hash(key)].key)) {
      if (M->count >= TABLE_SIZE) { return false; }
      M->table[hash(key)].value = value;
      return true;
    } else {
      // kalo beda
      if (M->count >= TABLE_SIZE) { return false; }
      int cp = hash(key);
      while (strcmp(M->table[cp++].key, key)) {
        if (cp >= TABLE_SIZE) return false;
      }
      // ketemu cp yg mana
      M->table[cp].value = value;
      return true;
    }
  // wait kita peduli ga sih?
  // ga ngaruh jir
  } else {
    // ini berarti emang belom ada
    if (M->count >= TABLE_SIZE) { return false; }
    strcpy(M->table[hash(key)].key, key);
    M->table[hash(key)].value = value;
    M->table[hash(key)].status = SLOT_OCCUPIED;
    M->count++;
    return true;
  }

  return true;
}

/* Menghapus entry dengan key tertentu.
   - Jika key ditemukan, ubah status slot menjadi SLOT_DELETED dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool UNSET_SPELL(CipherHashMap *M, const char *key) {
  if (M->table[hash(key)].status == SLOT_OCCUPIED) {
    int cp = hash(key);
    while (strcmp(M->table[cp].key, key)) {
      cp++;
    }
    M->table[cp].status = SLOT_DELETED;
    return true;
  } else if (M->table[hash(key)].status == SLOT_DELETED) {
    int cp = hash(key);
    while (M->table[cp++].status != SLOT_OCCUPIED) {
      if (cp >= TABLE_SIZE) return false;
    }
    M->table[cp].status = SLOT_DELETED;
    return true;
  } 

  return false;
}

/* Mencari value berdasarkan key.
   - Jika ditemukan, tulis ke *value dan kembalikan true.
   - Jika tidak ditemukan, kembalikan false. */
bool FIND_SPELL(const CipherHashMap *M, const char *key, int *value) {
  int cp = hash(key);
  if (M->table[cp].status == SLOT_EMPTY) {
    return false;
  }
  while (strcmp(M->table[cp].key, key)) {
    cp++;
    if (cp >= TABLE_SIZE) return false;
  }
  if (M->table[cp].status != SLOT_OCCUPIED) return false;
  *value = M->table[cp].value; 
  return true;
}

/* Mencetak semua entry berstatus SLOT_OCCUPIED:
   key value
   Satu entry per baris. Urutan tidak harus terurut. */
void PRINT_HASHMAP(const CipherHashMap *M) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (M->table[i].status == SLOT_OCCUPIED) {
      printf("%s %d\n", M->table[i].key, M->table[i].value);
    }
  }
}
