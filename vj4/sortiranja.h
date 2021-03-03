#ifndef SORTIRANJA_H
#define SORTIRANJA_H

extern int choose_pivot;
extern int n_min;

int* generate(int n);
void print(int *niz, int n);
void selectionsort(int *niz, int n);
void insertionsort(int *niz, int n);
int partition(int *niz, int n);
void quicksort(int *niz, int n);
void swap(int *a, int *b);
void quicksort_pivot(int *niz, int n);
void quicksort_sel(int *niz, int n);
void quicksort_ins(int *niz, int n);
void merge(int *niz, int *niza, int na, int *nizb, int nb);
int* duplicate(int *niz, int n);
void mergesort(int *niz, int n);
double measure(void(*sort)(int *niz, int n), int *niz, int n);


#endif	