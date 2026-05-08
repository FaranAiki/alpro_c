#include "MesinKetik.h"

/*
#define CAPACITY 200

typedef char ElType;
typedef struct {
    ElType contents[CAPACITY];
    int nEff;
    int cursor; 
} ListKetik;
*/

/* ********** KONSTRUKTOR ********** */
void CreateList(ListKetik *L) {
  L->nEff = 0;
  L->cursor = 0;
}
/* I.S. L sembarang */
/* F.S. Terbentuk List L kosong dengan nEff = 0 dan cursor = 0 */

/* ********** SELEKTOR ********** */
int length(ListKetik L) {
  return L.nEff;
}

/* ********** FUNGSI ********** */

void typeChar(ListKetik *L, ElType x) {
  if (L->nEff == CAPACITY - 1)
    return;

  for (int i = length(*L); i > L->cursor; i--) {
    L->contents[i] = L->contents[i - 1];
  } 

  L->contents[L->cursor] = x;

  L->nEff++;
  L->cursor++;
}
/* I.S. L terdefinisi, mungkin penuh. */
/* F.S. Jika list belum penuh, karakter x disisipkan tepat pada posisi cursor. 
 * Semua karakter dari posisi cursor hingga akhir bergeser 1 langkah ke kanan. 
 * cursor kemudian bertambah 1. nEff bertambah 1. */

void backspace(ListKetik *L) {
  if (L->cursor == 0)
    return;

  for (int i = L->cursor; i <= length(*L); i++) {
    L->contents[i - 1] = L->contents[i];
  }  

  L->nEff--;
  L->cursor--;
}
/* I.S. L terdefinisi. */
/* F.S. Jika cursor > 0, karakter tepat di kiri kursor (posisi cursor - 1) dihapus.
 * Karakter di kanannya bergeser 1 langkah ke kiri.
 * cursor berkurang 1. nEff berkurang 1. */

void deleteAt(ListKetik *L, int idx) {
  for (int i = idx; i < length(*L); i++) {
    if (i + 1 >= CAPACITY - 1)
      L->contents[i] = L->contents[i + 1];
    else
      L->contents[i] = 0;
    
  }  
  L->nEff--;
}

void deleteAll(ListKetik *L, ElType x) {
  for (int i = 0; i < L->cursor; i++) {
    if (L->contents[i] == x) {
      deleteAt(L, i);
      L->cursor--;

    }
  }

  for (int i = L->cursor; i < length(*L); i++) {
    if (L->contents[i] == x) {
      deleteAt(L, i);
    }
  }
}
/* I.S. L terdefinisi. */
/* F.S. SELURUH kemunculan karakter x di dalam list dihapus.
 * Sisa karakter merapat ke kiri (collapse).
 * PERHATIAN: Jika karakter yang terhapus berada di sebelah KIRI kursor, 
 * kursor harus ikut bergeser ke kiri agar posisi relatifnya terjaga. */


/* ********** NAVIGASI KURSOR ********** */

void cursorLeft(ListKetik *L) {
  if (L->cursor)
    L->cursor--;
}
/* Jika cursor > 0, cursor mundur 1 langkah. */

void cursorRight(ListKetik *L) {
  if (L->cursor < L->nEff)
    L->cursor++;
}
/* Jika cursor < nEff, cursor maju 1 langkah. */

void cursorHome(ListKetik *L) {
  L->cursor = 0;
};
/* cursor pindah ke awal list (posisi 0). */

void cursorEnd(ListKetik *L) {
  L->cursor = L->nEff;
};
/* cursor pindah ke akhir teks (posisi nEff). */

void printTeks(ListKetik L) {
  for (int i = 0; i < length(L); i++) {
    putchar(L.contents[i]);
  }
  printf("\n");
}
/* I.S. L terdefinisi */
/* F.S. Mencetak karakter dalam L berderet, lalu cetak "\n" */

/*
int main() {
  ListKetik L;
  CreateList(&L);
  typeChar(&L, 'a');
  backspace(&L);
  typeChar(&L, '1');
  cursorLeft(&L);
  typeChar(&L, '2');
  backspace(&L);
  typeChar(&L, '3');
  printTeks(L);
}*/
