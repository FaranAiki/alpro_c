#ifndef ANTREAN_WAHANA_H
#define ANTREAN_WAHANA_H

#include "queue.h"

#define STARVATION_THRESHOLD 3  // Setelah 3x berturut-turut layani prioritas, layani 1x regular

/* Struktur sistem antrean wahana dengan dua queue: prioritas dan regular */
typedef struct {
    Queue prioritas;           // Antrean pengunjung dengan tiket prioritas
    Queue regular;             // Antrean pengunjung dengan tiket regular
    int currentTime;           // Waktu saat ini di sistem
    int priorityServedCount;   // Counter untuk mencegah starvation
} AntreanWahana;

/********** Konstruktor **********/
void CreateAntrean(AntreanWahana *aw, int startTime);
/* I.S. Sembarang
   F.S. Membuat sistem antrean wahana baru dengan:
        - Queue prioritas kosong
        - Queue regular kosong
        - currentTime = startTime
        - priorityServedCount = 0 */

/********** Operasi: Status Antrean **********/
boolean isAllEmpty(AntreanWahana aw);
/* Mengirim true jika kedua antrean (prioritas dan regular) kosong */

boolean isPrioritasEmpty(AntreanWahana aw);
/* Mengirim true jika antrean prioritas kosong */

boolean isRegularEmpty(AntreanWahana aw);
/* Mengirim true jika antrean regular kosong */

int totalLength(AntreanWahana aw);
/* Mengirim total jumlah pengunjung di kedua antrean */

int lengthPrioritas(AntreanWahana aw);
/* Mengirim jumlah pengunjung di antrean prioritas */

int lengthRegular(AntreanWahana aw);
/* Mengirim jumlah pengunjung di antrean regular */

/********** Operasi: Manajemen Pengunjung **********/
void AddPengunjung(AntreanWahana *aw, Pengunjung p, boolean isPriority);
/* Menambahkan pengunjung ke antrean yang sesuai
   I.S. aw terdefinisi, p adalah pengunjung valid
   F.S. Jika isPriority = true, p ditambahkan ke antrean prioritas
        Jika isPriority = false, p ditambahkan ke antrean regular */

boolean ServeNext(AntreanWahana *aw, Pengunjung *served);
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

void RemoveTimedOut(AntreanWahana *aw);
/* Menghapus pengunjung yang sudah menunggu terlalu lama
   I.S. aw terdefinisi, currentTime sudah diupdate
   F.S. Semua pengunjung yang (currentTime - arrivalTime) > patience dihapus
        dari kedua antrean */

void UpdateTime(AntreanWahana *aw, int newTime);
/* Mengupdate waktu sistem
   I.S. aw terdefinisi, newTime >= currentTime
   F.S. currentTime = newTime */

Pengunjung PeekNextPrioritas(AntreanWahana aw);
/* Melihat pengunjung di depan antrean prioritas tanpa menghapus
   I.S. aw terdefinisi, antrean prioritas tidak kosong
   F.S. Mengembalikan pengunjung di HEAD antrean prioritas */

Pengunjung PeekNextRegular(AntreanWahana aw);
/* Melihat pengunjung di depan antrean regular tanpa menghapus
   I.S. aw terdefinisi, antrean regular tidak kosong
   F.S. Mengembalikan pengunjung di HEAD antrean regular */

#endif
