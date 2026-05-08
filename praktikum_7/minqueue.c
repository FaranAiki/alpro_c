#include "minqueue.h"
// #include "stack.c"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor *** */
void CreateMinQueue(MinQueue *mq) {
/* K.A. mq tidak terdefinisi */
/* K.A. Semua empat stack internal diinisialisasi dan kosong */
  CreateStack(&(mq->sIn));
  CreateStack(&(mq->sInMin));
  CreateStack(&(mq->sOut));
  CreateStack(&(mq->sOutMin));
}

/* *** Predikat *** */
boolean isMQEmpty(MinQueue mq) {
/* Mengembalikan benar jika MinQueue tidak mengandung elemen */
  return isEmpty(mq.sIn) && isEmpty(mq.sOut);
}

boolean isMQFull(MinQueue mq) {
/* Mengembalikan benar jika MinQueue telah mencapai kapasitas gabungan maksimal */
  return isFull(mq.sIn) || isFull(mq.sOut);
}

/* *** Mutator *** */
void enqueue(MinQueue *mq, int val) {
/* K.A. mq tidak penuh */
/* K.A. val ditambahkan ke bagian belakang antrian. 
   Pelacakan minimum internal diperbarui dalam O(1). */
  push(&(mq->sIn), val);
   if (isEmpty(mq->sInMin)) {
      push(&(mq->sInMin), val);
    } else {
       int currentMin = TOP(mq->sInMin);
        if (val < currentMin) {
            push(&(mq->sInMin), val);
        } else {
            push(&(mq->sInMin), currentMin);
        }
    }
}

void dequeue(MinQueue *mq, int *val) {
/* K.A. mq tidak kosong */
/* K.A. val berisi elemen depan antrian. Elemen dihapus.
   Pelacakan minimum internal diperbarui dalam O(1). */
  if (isEmpty(mq->sOut)) {
    while (!isEmpty(mq->sIn)) {
      int temp, minTemp;
      pop(&(mq->sIn), &temp);
       pop(&(mq->sInMin), &minTemp);
          
      push(&(mq->sOut), temp);
      if (isEmpty(mq->sOutMin)) {
        push(&(mq->sOutMin), temp);
      } else {
        int currentMin = TOP(mq->sOutMin);
        if (temp < currentMin) {
          push(&(mq->sOutMin), temp);
        } else {
          push(&(mq->sOutMin), currentMin);
        }
      }
     }
  }
  pop(&(mq->sOut), val);
  int trash;
  pop(&(mq->sOutMin), &trash);
}

/* *** Aksesor *** */
int getMin(MinQueue mq) {
/* K.A. mq tidak kosong */
/* K.A. Mengembalikan elemen minimum absolut saat ini dalam MinQueue dalam waktu O(1). */
  if (isEmpty(mq.sIn)) {
    return  TOP(mq.sOutMin);
  } else if (isEmpty(mq.sOut)) {
    return TOP(mq.sInMin);
  } else {
    int minIn = TOP(mq.sInMin);
    int minOut = TOP(mq.sOutMin);
    return (minIn < minOut) ? minIn : minOut;
  }
}


/*
int main() {
  MinQueue mq;
  CreateMinQueue(&mq);

  int n; char param; int arg;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &param);
    switch(param) {
      case 'E':
        scanf("%d", &arg);
        if (!isMQFull(mq)) {
          printf("OK\n");
          enqueue(&mq, arg);
        }
        else 
          printf("PENUH\n");
        break;
      case 'D':
        if (!isMQEmpty(mq)) {
          dequeue(&mq, &arg);
          printf("%d", arg);
        } else {
          printf("KOSONG\n");
        }
        break;
      case 'C':
        if (!isMQEmpty(mq)) {
          printf("1\n");
        } else {
          printf("0\n");
        }
      case 'M':
        if (!isMQEmpty(mq)) {
          printf("%d\n", getMin(mq));
        } else {
          printf("KOSONG\n");
        }
        break;
    }
  }
}
*/
