#include "ListStatik.h"

// dibantu sama gemini wak
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// apa coba ini pake malloc atau apa dah
// lifetime-nya ngga bisa oit
void MakeEmptyList (TabInt *T) {
  T->Neff = 0;
}

int Length (TabInt T) {
  return T.Neff;
}

int MaxNbEl (TabInt T) {
  return MaxCapacity; // ???
}

IdxType GetFirstIdx (TabInt T) {
  if (T.Neff)
    return IdxMin;
  return -1;
}

IdxType GetLastIdx (TabInt T) {
  if (T.Neff)
    return T.Neff;
  return -1;
}

ElType GetElmtAt (TabInt T, IdxType i) {
  if (T.Neff)
    return T.TI[i];
  return ElUndef;
}

void SetTab (TabInt Tin, TabInt *Tout) {
  MakeEmptyList(Tout);
  Tout->Neff = Tin.Neff; 
  for (int i = 1; i <= Tin.Neff; i++)
    Tout->TI[i] = Tin.TI[i];
}


void SetEl (TabInt *T, IdxType i, ElType v) {
  T->TI[i] = v;
}


void SetNeff (TabInt *T, IdxType N) {
  T->Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i) {
  return IdxMin <= i && i <= MaxCapacity; 
}

boolean IsIdxEff (TabInt T, IdxType i) {
  return IdxMin <= i && i <= T.Neff; 
}


boolean IsEmpty (TabInt T) {
  if (T.Neff) return false;
  return true;
}

boolean IsFull (TabInt T) {
  return T.Neff == MaxCapacity;
}

void ShowAll (TabInt T) {
  if (!T.Neff) {
    printf("Tabel kosong\n");
    return;
  }
  putchar('[');
  printf("%d", T.TI[1]);
  for (int i = 2; i <= T.Neff; i++) {
    putchar(',');
    printf("%d", T.TI[i]);
  }
  printf("]\n");
}

// pass by value ngga ngaruh kowkakow
TabInt PlusTab (TabInt T1, TabInt T2) {
  if (T1.Neff != T2.Neff) return T1;
  for (int i = 1; i <= T1.Neff; i++)
    T1.TI[i] += T2.TI[i];
  return T1;
}

TabInt MinusTab (TabInt T1, TabInt T2) {
  if (T1.Neff != T2.Neff) return T1;
  for (int i = 1; i <= T1.Neff; i++)
    T1.TI[i] -= T2.TI[i];
  return T1;
}

ElType ValMax (TabInt T) {
  int oo = T.TI[1];
  for (int i = 1; i <= T.Neff; i++) {
    if (oo < T.TI[i]) oo = T.TI[i]; 
  }
  return oo;
}

ElType ValMin (TabInt T) {
  int oo = T.TI[1];
  for (int i = 1; i <= T.Neff; i++) {
    if (oo > T.TI[i]) oo = T.TI[i]; 
  }
  return oo;
}

IdxType IdxMaxTab (TabInt T) {
  int oo = 1;
  for (int i = 1; i <= T.Neff; i++) {
    if (T.TI[oo] < T.TI[i])
      oo = i;
  }
  return oo;
}

IdxType IdxMinTab (TabInt T){
  int oo = 1;
  for (int i = 1; i <= T.Neff; i++) {
    if (T.TI[oo] > T.TI[i])
      oo = i;
  }
  return oo;
}

TabInt ConcatTable (TabInt T1, TabInt T2) {
  for (int i = 1; i <= T2.Neff; i++) {
    T1.Neff++;
    T1.TI[T1.Neff] = T2.TI[i];
  }
  return T1;
}
