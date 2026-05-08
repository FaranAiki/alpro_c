/* File: anomalinangor.h */

#ifndef _ANOMALI_H
#define _ANOMALI_H

#include "boolean.h"
#include "listberkait.h"

/*
 * DILARANG melakukan iterasi menggunakan kombinasi for loop dan fungsi
 * getElmt() maupun length()! Penggunaan getElmt di dalam loop sangat tidak
 * efisien untuk Linked List dan akan membuat program Anda terkena 
 * Time Limit Exceeded (TLE) pada test case berukuran besar.
*/

/*
 * Fungsi isEscalating
 * Menerima input sebuah list linier L.
 * Mengembalikan true jika nilai elemen list terus meningkat
 * (strictly increasing) dari elemen pertama hingga elemen terakhir.
 * Jika list kosong atau hanya berisi 1 elemen, kembalikan true.
 */
boolean isEscalating(List L);

/*
 * Fungsi peakAnomaly
 * Menerima input sebuah list linier L.
 * Mengembalikan nilai elemen paling besar (maksimum) di dalam list L.
 * Prekondisi (I.S.): L tidak kosong.
 */
int peakAnomaly(List L);

#endif
