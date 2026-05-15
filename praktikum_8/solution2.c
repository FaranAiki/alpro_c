#include "listberkait.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk mengurutkan linked list
 * I.S. l terdefinisi, mungkin kosong
 * F.S. Jika ascending = true, elemen-elemen dalam list l terurut menaik
 *      Jika ascending = false, elemen-elemen dalam list l terurut menurun
 *
 * Contoh:
 * Jika l adalah [4,1,3,2,5] dan ascending = true,
 * maka setelah sortList(&l, true), l menjadi [1,2,3,4,5]
 *
 * Jika l adalah [4,1,3,2,5] dan ascending = false,
 * maka setelah sortList(&l, false), l menjadi [5,4,3,2,1]
 *
 * Jika l adalah [], maka list tetap []
 * Jika l adalah [7], maka list tetap [7]
 *
 */
int findmax(List l) {
  int max = INFO(l);
  l = NEXT(l);
  while (l) {
    if (max < INFO(l)) max = INFO(l);
    l = NEXT(l);
  }
  return max;
}

int findmin(List l) {
  int min = INFO(l);
  l = NEXT(l);
  while (l) {
    if (min > INFO(l)) min = INFO(l);
    l = NEXT(l);
  }
  return min;
}

void sortList(List *l, boolean ascending) {
  List tmp;
  List curr = *l;
  int t;
  CreateList(&tmp);
  while (*l) {
    if (ascending) {
      int m = findmin(*l);
      deleteAt(l, indexOf(*l, m), &t);
      insertLast(&tmp, m);
    }
    else
    {
      int m = findmax(*l);
      deleteAt(l, indexOf(*l, m), &t);
      insertLast(&tmp, m);
    }
  }
  *l = tmp;
}

/*
int main() {
  List l;
  CreateList(&l);
  insertLast(&l, 5);
  insertLast(&l, 4);
  insertLast(&l, 3);
  insertLast(&l, 5);
  insertLast(&l, 6);
  printf("%d %d\n", findmin(l), findmax(l));
  sortList(&l, true);
  displayList(l);
  sortList(&l, false);
  displayList(l);
}
*/
