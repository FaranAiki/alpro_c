#include "PortalMap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
#ifndef PORTALMAP_H
#define PORTALMAP_H

#include <stdbool.h>

#define MAX_PORTALS 100
#define MAX_KEY_LEN 64
*/

/* ADT map array key-value untuk menyimpan data portal (mendekati hash map). */
/*
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} PortalRecord;

typedef struct {
  PortalRecord records[MAX_PORTALS];
    int count;
} PortalMap;
*/

/* Inisialisasi map kosong. Parameter: M = map yang akan diinisialisasi. */
void CREATE_MAP(PortalMap *M) {
  M->count = 0;
}

/* Tambah/update pasangan key-value. Jika key sudah ada, value diperbarui. */
void PUT(PortalMap *M, const char *key, int value) {
  if (!EXISTS(M, key)) {
    strcpy(M->records[M->count].key, key);
    M->records[M->count].value = value;
    M->count++;
    return;
  }

  int index = 0;
  while (strcmp(key, M->records[index].key)) {
      index++;
  }
  M->records[index].value = value; 
}

/* Ambil value dari key. Return true jika key ditemukan, false jika tidak. */
bool GET(const PortalMap *M, const char *key, int *value) {
  if (!EXISTS(M, key)) return false;
  int index =0 ;
  while (strcmp(key, M->records[index].key)) {
      index++;
  }

  *value = M->records[index].value;
  return true;
}

/* Cek apakah key ada di map. Return true jika ada, false jika tidak. */
bool EXISTS(const PortalMap *M, const char *key) {
  for (int i = 0; i < M->count; i++) {
    if (!strcmp(key, M->records[i].key))
      return true;
  }
  return false;
}

/* Hapus key jika ada. Return true jika berhasil dihapus, false jika tidak ditemukan. */
bool REMOVE_KEY(PortalMap *M, const char *key) {
  if (!EXISTS(M, key)) {
    return false;
  }
  int index = 0;
  while (strcmp(key, M->records[index].key)) {
      index++;
  }
  for (int i = index; i < M->count - 1; i++) {
    M->records[i] = M->records[i + 1]; 
  }
  M->count--;
  return true;
}

/* Jumlah key aktif saat ini. */
int SIZE(const PortalMap *M) { return M->count; }

/*
 int main() {
    PortalMap M;
    CREATE_MAP(&M);

    char cmd[32];
    char key[MAX_KEY_LEN];
    int val;

    while (scanf("%31s", cmd) != EOF) {
      if (strcmp(cmd, "PUT") == 0) {
        scanf("%63s %d", key, &val);
        PUT(&M, key, val);
      } else if (strcmp(cmd, "GET") == 0) {
        scanf("%63s", key);
        if (GET(&M, key, &val)) {
          printf("%d\n", val);
        } else {
          printf("NOT_FOUND\n");
        }
      } else if (strcmp(cmd, "EXISTS") == 0) {
        scanf("%63s", key);
        printf("%s\n", EXISTS(&M, key) ? "YES" : "NO");
      } else if (strcmp(cmd, "REMOVE") == 0) {
        scanf("%63s", key);
        REMOVE_KEY(&M, key);
      } else if (strcmp(cmd, "SIZE") == 0) {
        printf("%d\n", SIZE(&M));
      }
    }

    return 0;
  }
*/
