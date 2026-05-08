#include <stdio.h>
#include <string.h>
#include "GnomeTracker.h"
#include "boolean.h"

// ga full gemini, tapi 50% 50 maaf saya sibuk oii hueee
// Asumsi konstanta dari header jika belum ada
#ifndef IDX_UNDEF
#define IDX_UNDEF -1
#endif

/* ********** KONSTRUKTOR ********** */
void createTracker(GnomeTrack *L) {
    L->nEff = 0;
}

/* ********** SELEKTOR ********** */
int length(GnomeTrack L) {
    return L.nEff;
}

int maximumCap() { 
    return CAPACITY; 
}

IdxType getFirstIdx(GnomeTrack L) {
    // Kembalikan 0 jika ada isinya, jika tidak -1 (IDX_UNDEF)
    // ^ lupa ini kwoakow
    if (L.nEff > 0) return 0;
    return IDX_UNDEF;
}

IdxType getLastIdx(GnomeTrack L) {
    // Indeks terakhir adalah jumlah elemen dikurang 1 (karena 0-indexed)
    // ^ oke gemini
    if (L.nEff > 0) return L.nEff - 1;
    return IDX_UNDEF;
}

Gnome getElmt(GnomeTrack L, IdxType i) {
    return L.contents[i];
}

/* ********** SETTER ********** */
void setElmt(GnomeTrack *L, IdxType i, Gnome val) {
    L->contents[i] = val;
}

void setLength(GnomeTrack *L, int N) {
    L->nEff = N;
}

/* ********** Validasi INDEKS ********** */
boolean isIdxValid(IdxType i) {
    return 0 <= i && i <= CAPACITY - 1;
}

boolean isIdxEff(GnomeTrack L, IdxType i) {
    return 0 <= i && i <= L.nEff - 1;
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(GnomeTrack L) { 
    return L.nEff == 0; 
}

boolean isFull(GnomeTrack L) { 
    // Penuh jika nEff sama dengan CAPACITY, bukan CAPACITY - 1
    // ^ kata gemini gini, but idk aku percaya aja
    return L.nEff == CAPACITY; 
}

// ini baru gemini
void insertAt(GnomeTrack *L, Gnome g, IdxType idx) {
  // ohhh iya bisa cek is full dulu, 
  // modular programming
    if (!isFull(*L) && idx >= 0 && idx <= L->nEff) {
        // Geser semua elemen ke kanan dari belakang
        for (int i = L->nEff; i > idx; i--) {
            L->contents[i] = L->contents[i - 1];
        }
        L->contents[idx] = g;
        L->nEff++;
    }
}

void insertFirst(GnomeTrack *L, Gnome g) {
    insertAt(L, g, 0);
}

void insertLast(GnomeTrack *L, Gnome g) {
    insertAt(L, g, L->nEff);
}

void deleteAt(GnomeTrack *L, IdxType idx, Gnome *g) {
    if (!isEmpty(*L) && isIdxEff(*L, idx)) {
        // Simpan elemen yang akan dihapus
        *g = L->contents[idx]; // ini kek pop kah
        // Geser semua elemen setelahnya ke kiri
        for (int i = idx; i < L->nEff - 1; i++) {
            L->contents[i] = L->contents[i + 1];
        }
        L->nEff--;
    }
}

void deleteFirst(GnomeTrack *L, Gnome *g) {
    deleteAt(L, 0, g);
}

void deleteLast(GnomeTrack *L, Gnome *g) {
    deleteAt(L, L->nEff - 1, g);
}

IdxType indexOf(GnomeTrack L, int id) {
    for (int i = 0; i < L.nEff; i++) {
        if (L.contents[i].id == id) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void printAllGnome(GnomeTrack L) {
    if (isEmpty(L)) {
        printf("List kosong\n");
        return;
    }
    for (int i = 0; i < L.nEff; i++) {
        printf("Gnome Entry-%d:\n", i);
        printf("ID=%d\n", L.contents[i].id);
        printf("NAME=%s\n", L.contents[i].name);
        printf("HEIGHT=%.2f\n", L.contents[i].height);
        printf("TYPE=%s\n", L.contents[i].type);
        printf("FRIENDLY=%s\n", L.contents[i].isFriendly ? "Yes" : "No");
        
        // HANYA cetak baris kosong jika BUKAN elemen terakhir
        if (i < L.nEff - 1) {
            printf("\n"); 
        }
    }
}

void deleteUnfriendly(GnomeTrack *L) {
    if (isEmpty(*L)) {
        printf("List kosong\n");
        return;
    }
    
    int i = 0;
    while (i < L->nEff) {
        if (!L->contents[i].isFriendly) {
            printf("DELETED: %s\n", L->contents[i].name);
            Gnome g;
            deleteAt(L, i, &g);
        } else {
            i++; 
        }
    }
}

void filterByHeight(GnomeTrack L, float minHeight) {
    if (isEmpty(L)) {
        printf("List kosong\n");
        return;
    }
    
    boolean isFirst = true;
    for (int i = 0; i < L.nEff; i++) {
        if (L.contents[i].height >= minHeight) {
            if (!isFirst) {
                printf("\n"); // Cetak pemisah sebelum elemen (kecuali yang pertama)
            }
            printf("Gnome Entry-%d:\n", i);
            printf("ID=%d\n", L.contents[i].id);
            printf("NAME=%s\n", L.contents[i].name);
            printf("HEIGHT=%.2f\n", L.contents[i].height);
            printf("TYPE=%s\n", L.contents[i].type);
            printf("FRIENDLY=%s\n", L.contents[i].isFriendly ? "Yes" : "No");
            isFirst = false;
        }
    }
}

void filterByType(GnomeTrack L, char *targetType) {
    if (isEmpty(L)) {
        printf("List kosong\n");
        return;
    }
    
    boolean isFirst = true;
    for (int i = 0; i < L.nEff; i++) {
        if (strcmp(L.contents[i].type, targetType) == 0) {
            if (!isFirst) {
                printf("\n"); // Cetak pemisah sebelum elemen (kecuali yang pertama)
            }
            printf("Gnome Entry-%d:\n", i);
            printf("ID=%d\n", L.contents[i].id);
            printf("NAME=%s\n", L.contents[i].name);
            printf("HEIGHT=%.2f\n", L.contents[i].height);
            printf("TYPE=%s\n", L.contents[i].type);
            printf("FRIENDLY=%s\n", L.contents[i].isFriendly ? "Yes" : "No");
            isFirst = false;
        }
    }
}

// latihan lg
