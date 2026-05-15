#include "listberkait.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk membalik linked list secara in-place
 * I.S. l terdefinisi, mungkin kosong
 * F.S. Elemen-elemen dalam list l dibalik urutannya
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah reverseList(&l), l menjadi [5,4,3,2,1]
 * Jika l adalah [], maka setelah reverseList(&l), l tetap []
 * Jika l adalah [1], maka setelah reverseList(&l), l tetap [1]
 *
 */
void reverseList(List *l) {
  Address curr = NULL;
  Address next = NULL;
  Address prev = NULL;
  while (*l) {
  //displayList(*l); putchar('\n');
    next = NEXT(*l);
    NEXT(*l) = prev; 
    prev = *l;
    if (next)
    *l = next;
    else break;
  }
}

/*
int main() {
  List l;
  CreateList(&l);
  insertLast(&l, 1);
  insertLast(&l, 3);
  insertLast(&l, 4);
  insertLast(&l, 5);
  insertLast(&l, 6);
  displayList(l); putchar('\n');
  reverseList(&l);
  displayList(l);
}*/
