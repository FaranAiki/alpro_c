#include "JadwalNangor.h"

/*
#define CAPACITY 100

typedef int ElType;
typedef struct {
    ElType contents[CAPACITY];
    int nEff;
} ListEkspedisi;

*/

typedef int boolean;

boolean isEmpty(ListEkspedisi L) { 
    return L.nEff == 0; 
}

boolean isFull(ListEkspedisi L) { 
    // Penuh jika nEff sama dengan CAPACITY, bukan CAPACITY - 1
    // copas dari prapraktikum
    return L.nEff == CAPACITY; 
}

// ini dibuat oleh gemini dari prapraktikum, logika sama aja
void insertAt(ListEkspedisi *L, ElType x, int idx) {
  // ohhh iya bisa cek is full dulu, 
  // modular programming
    // copas dari prapraktikum
    if (!isFull(*L) && idx >= 0 && idx <= L->nEff) {
        // Geser semua elemen ke kanan dari belakang
        for (int i = L->nEff; i > idx; i--) {
            L->contents[i] = L->contents[i - 1];
        }
        L->contents[idx] = x;
        L->nEff++;
    }
}

/* ********** KONSTRUKTOR ********** */
void CreateList(ListEkspedisi *L) {
  L->nEff = 0;
}
/* I.S. L sembarang */
/* F.S. Terbentuk List L kosong dengan nEff = 0 */

/* ********** SELEKTOR ********** */
int length(ListEkspedisi L) {
  return L.nEff;
}
/* Mengirimkan banyaknya elemen efektif list */

/* ********** OPERASI UJUNG LIST ********** */
void insertFirst(ListEkspedisi *L, ElType x) {
  // geser dari kanan malah
  insertAt(L, x, 0);
}
/* I.S. L terdefinisi, mungkin kosong, tidak penuh. */
/* F.S. x disisipkan sebagai elemen pertama L. */
/* HINT: lakukan pergeseran */

void insertLast(ListEkspedisi *L, ElType x) {
  // geser dari kanan malah
  insertAt(L, x, L->nEff);
}
/* I.S. L terdefinisi, mungkin kosong, tidak penuh. */
/* F.S. x disisipkan sebagai elemen terakhir L. */

void deleteAt(ListEkspedisi *L, int idx, ElType *x) {
    if (!isEmpty(*L) && idx >= 0 && idx <= L->nEff - 1) {
        *x = L->contents[idx]; // ini kek pop kah
        for (int i = idx; i < L->nEff - 1; i++) {
            L->contents[i] = L->contents[i + 1];
        }
        L->nEff--;
    }
}

void deleteFirst(ListEkspedisi *L, ElType *x) {
    deleteAt(L, 0, x);
}

void deleteLast(ListEkspedisi *L, ElType *x) {
    deleteAt(L, L->nEff - 1, x);
}

/* ********** OPERASI TAMBAHAN ********** */
int TotalJarak(ListEkspedisi L) {
  if (!L.nEff) return 0;
  int total = 0;
  for (int i = 0; i < L.nEff; i++) 
    total += L.contents[i];
  return total;
}
/* Mengembalikan jumlah total nilai semua elemen di dalam List. Kembalikan 0 jika kosong. */

void printList(ListEkspedisi L) {
  if (!L.nEff) { 
    printf("[]\n");
    return;
  }

  putchar('[');
  printf("%d", L.contents[0]);
  for (int i = 1; i < L.nEff; i++) {
    putchar(',');
    printf("%d", L.contents[i]);
  }
  printf("]\n");
}
/* Mencetak isi list dengan format [x1,x2,...,xn] diakhiri newline (\n). */

