#ifndef PORTALMAP_H
#define PORTALMAP_H

#include <stdbool.h>

#define MAX_PORTALS 100
#define MAX_KEY_LEN 64

/* ADT map array key-value untuk menyimpan data portal (mendekati hash map). */
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} PortalRecord;

typedef struct {
  PortalRecord records[MAX_PORTALS];
    int count;
} PortalMap;

/* Inisialisasi map kosong. Parameter: M = map yang akan diinisialisasi. */
void CREATE_MAP(PortalMap *M);

/* Tambah/update pasangan key-value. Jika key sudah ada, value diperbarui. */
void PUT(PortalMap *M, const char *key, int value);

/* Ambil value dari key. Return true jika key ditemukan, false jika tidak. */
bool GET(const PortalMap *M, const char *key, int *value);

/* Cek apakah key ada di map. Return true jika ada, false jika tidak. */
bool EXISTS(const PortalMap *M, const char *key);

/* Hapus key jika ada. Return true jika berhasil dihapus, false jika tidak ditemukan. */
bool REMOVE_KEY(PortalMap *M, const char *key);

/* Jumlah key aktif saat ini. */
int SIZE(const PortalMap *M);

#endif
