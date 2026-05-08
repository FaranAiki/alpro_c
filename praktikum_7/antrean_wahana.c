
#include "queue.h"
#include "antrean_wahana.h"

/*
typedef struct {
    Queue prioritas;           // Antrean pengunjung dengan tiket prioritas
    Queue regular;             // Antrean pengunjung dengan tiket regular
    int currentTime;           // Waktu saat ini di sistem
    int priorityServedCount;   // Counter untuk mencegah starvation
} AntreanWahana;
*/

void CreateAntrean(AntreanWahana *aw, int startTime)
/* I.S. Sembarang
   F.S. Membuat sistem antrean wahana baru dengan:
        - Queue prioritas kosong
        - Queue regular kosong
        - currentTime = startTime
        - priorityServedCount = 0 */
{
  aw->currentTime = startTime;
  aw->priorityServedCount = 0;
  CreateQueue(&(aw->prioritas));
  CreateQueue(&(aw->regular));
}

boolean isPrioritasEmpty(AntreanWahana aw)
/* Mengirim true jika antrean prioritas kosong */
{
  return (isEmpty(aw.prioritas));
}

boolean isRegularEmpty(AntreanWahana aw)
/* Mengirim true jika antrean regular kosong */
{
  return (isEmpty(aw.regular));
}

// biar lebih elegan kita tuker ye
boolean isAllEmpty(AntreanWahana aw)
/* Mengirim true jika kedua antrean (prioritas dan regular) kosong */
{
  return (isPrioritasEmpty(aw) && isRegularEmpty(aw));
}


int lengthPrioritas(AntreanWahana aw)
/* Mengirim jumlah pengunjung di antrean prioritas */
{
  return (length(aw.prioritas)); 
}

int lengthRegular(AntreanWahana aw)
/* Mengirim jumlah pengunjung di antrean regular */
{
  return (length(aw.regular)); 
}

// tuker lagi
int totalLength(AntreanWahana aw)
/* Mengirim total jumlah pengunjung di kedua antrean */
{
  return (lengthRegular(aw) + lengthPrioritas(aw)); 
}

void AddPengunjung(AntreanWahana *aw, Pengunjung p, boolean isPriority)
/* Menambahkan pengunjung ke antrean yang sesuai
   I.S. aw terdefinisi, p adalah pengunjung valid
   F.S. Jika isPriority = true, p ditambahkan ke antrean prioritas
        Jika isPriority = false, p ditambahkan ke antrean regular */
{
  if (isPriority)
   enqueue(&(aw->prioritas), p);
  else 
    enqueue(&(aw->regular), p);
}

boolean ServeNext(AntreanWahana *aw, Pengunjung *served)
/* Melayani pengunjung berikutnya dengan logika starvation prevention
   I.S. aw terdefinisi
   F.S. Mengembalikan true dan mengisi served dengan pengunjung yang dilayani jika ada
        Mengembalikan false jika kedua antrean kosong
   Logika:
   - Jika priorityServedCount < STARVATION_THRESHOLD dan antrean prioritas tidak kosong:
     layani dari prioritas
   - Jika priorityServedCount >= STARVATION_THRESHOLD dan antrean regular tidak kosong:
     layani dari regular, reset counter
   - Jika salah satu antrean kosong, layani dari yang tidak kosong */
{
  if (isAllEmpty(*aw))
    return false;

  if (aw->priorityServedCount < STARVATION_THRESHOLD && !isEmpty(aw->prioritas)) {
    // layanin maksudnya dequeue 
    dequeue(&(aw->prioritas), served);
    aw->priorityServedCount++;
  } else if (!isEmpty(aw->regular)) {
    dequeue(&(aw->regular), served);
    aw->priorityServedCount = 0;
  } else {
    dequeue(&(aw->prioritas), served);
    aw->priorityServedCount++;
  }
  return true;
}

// gimana cara loop bjir
void RemoveTimedOut(AntreanWahana *aw)
/* Menghapus pengunjung yang sudah menunggu terlalu lama
   I.S. aw terdefinisi, currentTime sudah diupdate
   F.S. Semua pengunjung yang (currentTime - arrivalTime) > patience dihapus
        dari kedua antrean */
{
 // bodo maat 
  Queue tempP, tempR;
  Pengunjung p;
  CreateQueue(&tempP);
  CreateQueue(&tempR);

  while (!isEmpty(aw->regular)) {
    dequeue(&(aw->regular), &p);
    if (aw->currentTime - p.arrivalTime <= p.patience) {
      enqueue(&tempR, p);
    }
  }
  aw->regular = tempR;

  while (!isEmpty(aw->prioritas)) {
    dequeue(&(aw->prioritas), &p);
    if (aw->currentTime - p.arrivalTime <= p.patience) {
      enqueue(&tempP, p);
    }
  }
  aw->prioritas = tempP;
}

void UpdateTime(AntreanWahana *aw, int newTime)
/* Mengupdate waktu sistem
   I.S. aw terdefinisi, newTime >= currentTime
   F.S. currentTime = newTime */
{
   /*F.S.*/ aw->currentTime = newTime;
}


Pengunjung PeekNextPrioritas(AntreanWahana aw)
/* Melihat pengunjung di depan antrean prioritas tanpa menghapus
   I.S. aw terdefinisi, antrean prioritas tidak kosong
   F.S. Mengembalikan pengunjung di HEAD antrean prioritas */
{
  return front(aw.prioritas);
}

Pengunjung PeekNextRegular(AntreanWahana aw)
/* Melihat pengunjung di depan antrean regular tanpa menghapus
   I.S. aw terdefinisi, antrean regular tidak kosong
   F.S. Mengembalikan pengunjung di HEAD antrean regular */
{
  return front(aw.regular);
}
