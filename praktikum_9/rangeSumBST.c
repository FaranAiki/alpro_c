
#include "bst.h"

/****************** FUNGSI RANGE SUM ******************/
/* Menghitung jumlah total key dalam range [L, R] dengan mempertimbangkan count */
int rangeSumBST(BinTree p, int L, int R) {
  // kiri-kiri kanan?
  // apalah ga bisa iya wkwk cmn 1 poin
  if (isTreeEmpty(p)) return 0;
  int total = 0;

  if (ROOT(p).key >= L && ROOT(p).key <= R) {
    total += (ROOT(p).key * ROOT(p).count);
  }

  if (ROOT(p).key > L) {
    total += rangeSumBST(LEFT(p), L, R);
  }

  if (ROOT(p).key < R) {
    total += rangeSumBST(RIGHT(p), L, R);
  }

  return total;
}
/* I.S. p terdefinisi (bisa kosong atau tidak), L dan R terdefinisi
   F.S. Mengembalikan jumlah total dari semua key di dalam BST yang berada di range [L, R]
        Jika sebuah key memiliki count > 1, kontribusinya adalah key * count
        Range bersifat inklusif: L dan R ikut dihitung jika ditemukan
        Jika pohon kosong atau tidak ada node dalam range, return 0 */

