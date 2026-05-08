#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "pengunjung.h"
#include <stdio.h>
#include <stdlib.h>

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef Pengunjung ElType;

/* Contoh struktur type Queue: array statik, indeks head dan indeks tail disimpan */
typedef struct {
    ElType buffer[CAPACITY];
    int idxHead;
    int idxTail;
} Queue;

/* Definisi Queue kosong: idxHead = idxTail = IDX_UNDEF. */

/********** AKSES (Selektor) **********/
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/********** Konstruktor **********/
void CreateQueue(Queue *q);
/* I.S. Sembarang
   F.S. Membuat sebuah Queue q yang kosong berkapasitas CAPACITY
   jadi indeksnya antara 0..CAPACITY-1
   Ciri Queue kosong: idxHead dan idxTail bernilai IDX_UNDEF */

/********** Operasi: pemeriksaan status Queue **********/
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q);
/* Mengirim true jika penyimpanan q penuh */

int length(Queue q);
/* Mengirim jumlah elemen q saat ini */

/*** Primitif Add/Delete ***/
void enqueue(Queue *q, ElType val);
/* Proses: Menambahkan val sebagai elemen Queue q.
   I.S. queue mungkin kosong, TIDAK penuh
   F.S. queue bertambah elemen val sebagai tail yang baru, TAIL bergeser ke kanan
   Jika IDX_TAIL(queue)=CAPACITY-1, maka geser isi tabel, shg IDX_HEAD(queue)=0 */

void dequeue(Queue *q, ElType *val);
/* Menghapus head dari Queue q.
   I.S. queue tidak kosong
   F.S. val berisi nilai head yang lama.
   Jika queue tidak menjadi kosong,
   queue.idxHead berpindah ke elemen berikutnya pada queue.
   Jika menjadi kosong, idxHead dan idxTail = IDX_UNDEF */

ElType front(Queue q);
/* Mengembalikan elemen di head tanpa menghapusnya.
   I.S. queue tidak kosong
   F.S. mengembalikan nilai elemen HEAD(q) */

#endif
