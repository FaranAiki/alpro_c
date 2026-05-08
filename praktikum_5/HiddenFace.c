/* MODUL hidden face - LIST STATIK IMPLISIT */
/* Penempatan elemen tidak rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */


#include "boolean.h"
#include "HiddenFace.h"
#include <stdio.h>

/*
#define CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARK '\0' 

typedef char ElType;
typedef int IdxType;

typedef struct
{
    ElType contents[CAPACITY];
} HiddenFaces;


#define ELMT(l, i) (l).contents[(i)]
*/

/* ********** KONSTRUKTOR ********** */
// memset bisa
void CreateFaces(HiddenFaces *f) {
  for (int i = 0; i <= CAPACITY - 1; i++) {
    f->contents[i] = MARK;
  }
}
/* I.S. f sembarang */
/* F.S. Terbentuk list f kosong dengan semua elemen bernilai MARK */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(HiddenFaces f) {
  if (f.contents[0] == IDX_UNDEF)
    return true;
  return false;
}
/* Mengirimkan true jika list kosong */

boolean isFull(HiddenFaces f) {
  for (int i = 0; i < CAPACITY - 1; i++) {
    if (f.contents[i] == MARK) return false;
  }
  return true;
}
/* Mengirimkan true jika list penuh */

/* ********** SELEKTOR ********** */
int length(HiddenFaces f) {
  int panjang = 0;
  for (int i = 0; i <= CAPACITY - 1; i++) {
    if (f.contents[i] != MARK) panjang++;
  }
  return panjang;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Jika list kosong, mengembalikan 0 */

IdxType getFirstIdx(HiddenFaces f) {
  int idx = 0;
  while (f.contents[idx] == MARK) {
    idx++;
  }
  return idx;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(HiddenFaces f) {
  int idx = CAPACITY - 1;
  while (f.contents[idx] == MARK) {
    idx--;
  }
  return idx;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan indeks elemen terakhir */

ElType getElmt(HiddenFaces f, IdxType i) {
  return f.contents[i];
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan elemen list f yang ke-i */

void setElmt(HiddenFaces f, IdxType i, ElType val) {
  f.contents[i] = val;
}
/* Prekondisi : f tidak kosong */
/* Mengeset nilai elemen list yang ke-i sehingga bernilai val */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(HiddenFaces f, IdxType i) {
  if (0 <= i && i <= CAPACITY - 1) return true;
  return false;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(HiddenFaces f, IdxType i) {
  if (0 <= i && i <= getLastIdx(f)) return true;
  return false;
}
/* Prekondisi : f tidak kosong */
/* Mengirimkan true jika i adalah indeks efektif dalam list */

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */
void insertFirst(HiddenFaces *f, ElType val) {
  insertAt(f, val, getFirstIdx(*f));
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val sebagai elemen pertama */
/* Note: Dapat dipastikan ada ruang kosong sebelum elemen pertama */

void insertAt(HiddenFaces *f, ElType val, IdxType i) {
  // nah ini geser ngga
  for (int k = getLastIdx(*f); k >= i; k--) {
    f->contents[k + 1] = f->contents[k]; 
  }
  f->contents[i] = val; 
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val di indeks tertentu */
/* Note: Dapat dipastikan ada ruang kosong sebelum elemen pertama dan setelah elemen terakhir */

void insertLast(HiddenFaces *f, ElType val) {
  insertAt(f, val, getLastIdx(*f));
}
/* Prekondisi : f, val terdefinisi */
/* Menambahkan val sebagai elemen terakhir */
/* Note: Dapat dipastikan ada ruang kosong setelah elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */
void deleteFirst(HiddenFaces *f, ElType *val) {
  deleteAt(f, val, getFirstIdx(*f));
}
/* Prekondisi : f tidak kosong */
/* Menghapus elemen pertama */

void deleteAt(HiddenFaces *f, ElType *val, IdxType i) {
  *val = f->contents[i];
  f->contents[i] = MARK;
}
/* Prekondisi : f tidak kosong */
/* Menghapus elemen di indeks tertentu */

void deleteLast(HiddenFaces *f, ElType *val) {
  deleteAt(f, val, getLastIdx(*f));
};
/* Prekondisi : f tidak kosong */
/* Menghapus elemen terakhir */

/* ********** FUNGSI ANALISIS ********** */
void printAll(HiddenFaces f) {
  if (isEmpty(f)) { 
    printf("[]");
    return;
  }

  putchar('[');
  printf("'%c'", f.contents[getFirstIdx(f)]);
  for (int i = getFirstIdx(f); i <= getLastIdx(f); i++) {
    if (f.contents[i] != MARK) {
      putchar(',');
      printf("'%c'", f.contents[i]);
    }
  }
  printf("]\n");
}
/* Prekondisi : f terdefinisi */
/* Menampilkan semua elemen efektif dari list dalam format [x1,x2,...,xn] */
/* Contoh : */
/* ['a','b','c'] */
/* Jika kosong : []*/
/* Pastikan ada newline setelah list ditampilkan */

HiddenFaces concat(HiddenFaces f1, HiddenFaces f2) {
  HiddenFaces c;
  CreateFaces(&c); int last_index = 0;

  if (!isEmpty(f1))
  for (int i = 0; i <= getLastIdx(f1); i++) {
    if (f1.contents[i] != MARK) {
      c.contents[last_index] = f1.contents[i];
      last_index++;
    }
  }

  if (!isEmpty(f2))
  for (int i = 0; i <= getLastIdx(f2); i++) {
    if (f2.contents[i] != MARK) {
      c.contents[last_index] = f2.contents[i];
      last_index++;
    }
  }

  return c;
}
/* Prekondisi: f1 dan f2 terdefinisi, mungkin kosong. */
/* Mengembalikan hasil Konkatenasi dua buah list yang rata kiri, f2 ditaruh di belakang f1 */

