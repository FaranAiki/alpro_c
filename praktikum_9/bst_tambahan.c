/*
#ifndef BST_TAMBAHAN_H
#define BST_TAMBAHAN_H

*/
/* ********* FUNGSI TAMBAHAN BST ********* */
/* Mengirimkan true jika num ditemukan sebagai key pada tree p */
#include "bst.h"

boolean isInTree(BinTree p, int num)
{
  if (isTreeEmpty(p)) return false;
  if (ROOT(p).key == num) return true;
  if (num < ROOT(p).key) {
      return isInTree(LEFT(p), num);
  } else {
      return isInTree(RIGHT(p), num);
  }
}/* I.S. p terdefinisi
   F.S. Mengembalikan true jika terdapat node dengan key = num, false jika tidak */

/* Menghitung banyak daun (leaf) pada tree p */
int nbLeaf(BinTree p)
{
  if (isTreeEmpty(p)) return 0;
  if (isOneElmt(p)) return 1;
  return nbLeaf(LEFT(p)) + nbLeaf(RIGHT(p));
}
/* I.S. p terdefinisi
   F.S. Mengembalikan banyaknya node daun pada tree p
        Jika tree kosong, mengembalikan 0 */

/* Menjumlahkan nilai key pada semua daun (leaf) */
int sumLeaf(BinTree p) {
  if (isTreeEmpty(p)) return 0;
  if (isOneElmt(p)) {
      return ROOT(p).key;
  }
  return sumLeaf(LEFT(p)) + sumLeaf(RIGHT(p));
}
/* I.S. p terdefinisi
   F.S. Mengembalikan jumlah seluruh key pada node daun
        Jika tree kosong, mengembalikan 0 */

