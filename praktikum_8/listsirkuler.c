/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/*
#ifndef LISTSIRKULER_H
#define LISTSIRKULER_H

#include "boolean.h"

typedef int ElType;
typedef struct node *Address;
typedef struct node { 
	ElType info;
	Address next;
} ElmtList;
typedef struct {
	Address first;
} List;
*/

/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
/*
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(l) ((l).first)
*/

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
  return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  FIRST(*l) = NULL; 
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
    Address p = (Address) malloc(sizeof(struct node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void deallocate(Address P) {
  free(P); // FREE SLVESSS
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

Address lastElement(List l) {
  if (isEmpty(l)) return FIRST(l);
  Address curr = FIRST(l);
  while (curr) {
    if (NEXT(curr) == FIRST(l) || !NEXT(curr)) {
      return curr;
    }
    curr = NEXT(curr);
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address p = allocate(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
      if (isEmpty(*l)) {
        FIRST(*l) = p;
        NEXT(lastElement(*l)) = p;
      }
      else {
        NEXT(lastElement(*l)) = p;
        FIRST(*l) = p;
      }
    }
    // ubah shit biar yang belakang ke depan
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p = allocate(val);
        if (p != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address last = lastElement(*l);
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    NEXT(last) = FIRST(*l);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = FIRST(*l);
    Address prec = NULL;
    while (NEXT(p) != FIRST(*l)) {
        prec = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (prec == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(prec) = FIRST(*l);
    }
    free(p);
}

void displayList(List l) {
    if (isEmpty(l)) {
      printf("[]");
      return;
    }

    printf("[");
    Address p = FIRST(l);
    printf("%d", INFO(p));
    if (NEXT(p) != FIRST(l)) {
      printf(",");
    }
    p = NEXT(p);
    while (p != FIRST(l)) {
        printf("%d", INFO(p));
        if (NEXT(p) != FIRST(l)) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

/*
int main() {
  List l; int t;
  CreateList(&l);
  insertLast(&l, 5);
  // insertLast(&l, 4);
  insertFirst(&l, 1);
  deleteFirst(&l, &t);
  deleteLast(&l, &t);
  // insertLast(&l, 100);
  // insertLast(&l, 5);
  // insertLast(&l, 3);
  // insertLast(&l, 5);
  // insertLast(&l, 6);
  displayList(l);
}
*/
