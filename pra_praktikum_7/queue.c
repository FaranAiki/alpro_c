#include "queue.h"

/* Definisi Queue kosong: idxHead = idxTail = IDX_UNDEF. */

/********** Konstruktor **********/
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/********** Operasi: pemeriksaan status Queue **********/
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return length(q) == CAPACITY;
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/*** Primitif Add/Delete ***/
void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == CAPACITY - 1) {
            // Geser isi tabel sehingga IDX_HEAD(q) = 0
            int l = length(*q);
            for (int i = 0; i < l; i++) {
                q->buffer[i] = q->buffer[IDX_HEAD(*q) + i];
            }
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = l - 1;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        // Queue menjadi kosong
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

ElType front(Queue q) {
    return HEAD(q);
}
