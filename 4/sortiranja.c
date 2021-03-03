#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int choose_pivot = 1;
int n_min = 0;

// generiranje i ispis niza
int* generate(int n) {
	int i;
	int *niz = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		niz[i] = rand() % 1000;
	return niz;
}

void print(int *niz, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}

// selection sort
void selectionsort(int *niz, int n) {
	int i;
	for (i = 0; i < n - 1; i++) { 
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++) {
			if (niz[j] < niz[maxi])
				maxi = j;
		}

		tmp = niz[maxi];
		niz[maxi] = niz[i];
		niz[i] = tmp;
	}
}

// insertion sort
void insertionsort(int *niz, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			int tmp;
			tmp = niz[j-1];
			niz[j - 1] = niz[j];
			niz[j] = tmp;
			j--;
		}
	}
}

// quick sort
int partition(int *niz, int n) {
	int l, r;
	l = 1;
	r = n - 1;
	while (l < r) {
		if (niz[r] >= niz[0]) {
			r--;
		}
		else if (niz[l] < niz[0]) {
			l++;
		}
		else {
			int tmp = niz[l];
			niz[l] = niz[r];
			niz[r] = tmp;
		}
	}
	if (niz[0] < niz[r]) { // 1
		return 0;
	}
	else { // 3
		int tmp = niz[r];
		niz[r] = niz[0];
		niz[0] = tmp;
		return r;
	}
}

void quicksort(int *niz, int n) {
	if (n < 2)
		return;
	int pi = partition(niz, n);
	quicksort(niz, pi);
	quicksort(niz + pi + 1, n - pi - 1);
}
void zamijeni(int *a, int *b)
{
	int *tmp = *a;
	*a = *b;
	*b = tmp;
}
void quicksort_pivot(int *niz, int n) {
	if (choose_pivot)
	{
		if (niz[n / 2]<niz[0] && niz[n / 2]>niz[n - 1] || niz[n / 2]<niz[n - 1] && niz[n / 2]>niz[0]) {
			zamijeni(&niz[n / 2], &niz[0]);
		}
		else if (niz[n - 1]<niz[0] && niz[n - 1]>niz[n / 2] || niz[n - 1] < niz[n / 2] && niz[n - 1]>niz[0]) {
			zamijeni(&niz[n - 1], &niz[0]);
		}
	}
	if (n < 2)
		return;
	int pi = partition(niz, n);
	quicksort(niz, pi);
	quicksort(niz + pi + 1, n - pi - 1);
}
void quicksort_ins(int *niz, int n)
{
	if (n < 2)
		return;
	if (n < n_min)
		insertionsort(niz, n);
	else
	{
		int pi = partition(niz, n);
		quicksort(niz, pi);
		quicksort(niz + pi + 1, n - pi - 1);
	}
}
void quicksort_sel(int *niz, int n)
{
	if (n < 2)
		return;
	if (n < n_min)
		selectionsort(niz, n);
	else
	{
		int pi = partition(niz, n);
		quicksort(niz, pi);
		quicksort(niz + pi + 1, n - pi - 1);
	}
}
// alocira i vraæa kopiju niza
int* duplicate(int *niz, int n) {
	int i;
	int *novi = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		novi[i] = niz[i];
	}
	return novi;
}

double measure(void(*sort)(int *niz, int n), int *niz, int n) {
	int start_time = clock();
	sort(niz, n);
	int end_time = clock();
	return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}
