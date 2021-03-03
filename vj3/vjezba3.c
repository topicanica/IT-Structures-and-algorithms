#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *generiraj(int n)
{
	
	int *niz = (int*)malloc(n * sizeof(int));
	niz[0] = rand() % 10;
	int i;
	for (i = 1; i < n; i++)
	{
		niz[i] = niz[i - 1] + rand() % 10 + 1;
	}
	return niz;
}
void shuffle(int *skup, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int j = rand() % n;
		int tmp = skup[i];
		skup[i] = skup[j];
		skup[j] = tmp;
	}
}
void printaj(int *niz,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d", niz[i]);
	}
	printf("\n");
}
int *presjek(int *skupA, int dulj1, int *skupB, int dulj2) {
	int *presjek;
	int i, j, k = 0;
	int veci_n = (dulj1 > dulj2) ? dulj1 : dulj2;
	presjek = (int*)malloc(veci_n * sizeof(int));
	for (i = 0; i < dulj1; i++) {
		for (j = 0; j < dulj2; j++) {
			if (skupA[i] == skupB[j]) {
				presjek[k] = skupA[i];
				k++;
			}
		}
	}
	return presjek;
}
int bsu(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int *presjek_sortiran(int *skupA, int *skupB, int dulj1, int dulj2)
{
	int i, brojac = 0;
	int veci = (dulj1 > dulj2) ? dulj1 : dulj2;
	int *pres_sort = (int*)malloc(veci * sizeof(int));
	for (i = 0; i < dulj1; i++)
	{
		int *privremeni= (int*)bsearch(&skupA, skupB, dulj2, sizeof(int), bsu);
		if (privremeni!=NULL)
		{
			pres_sort[brojac] = privremeni[i];
			brojac++;
		}

	}
	return pres_sort;
}

int main() {
	srand(time(NULL));

	int *niz1, *niz2;
	int n1 = 30000;
	int n2 = 10000;

	clock_t pocetak, kraj;
	double ukupno_vrijeme;
	int i;

	int *presj;
	n1 = 30000;
	niz1 = generiraj(n1);
	shuffle(niz1, n1);
	for (i = 10000; i <= 50000; i += 5000) {
		niz2 = generiraj(i);
		shuffle(niz2, i);
		pocetak = clock();
		presj = presjek(niz1, n1, niz2, i);
		kraj = clock();
		ukupno_vrijeme = ((double)(kraj - pocetak) / CLOCKS_PER_SEC);
		printf("presjek dva nesortirana niza (%d): %f\n", i, ukupno_vrijeme);
		free(niz2);
		free(presj);
	}

	int *presj_sort;
	n2 = 30000;
	niz2 = generiraj(n2);
	for (i = 10000; i <= 50000; i += 5000) {
		niz1 = generiraj(i);
		shuffle(niz1, i);
		pocetak = clock();
		presj_sort = presjek_sortiran(niz1, n1, niz2, n2);
		kraj = clock();
		ukupno_vrijeme = ((double)(kraj - pocetak) / CLOCKS_PER_SEC);
		printf("presjek nesortiranog i sortiranog niza (%d): %f\n", i, ukupno_vrijeme);
		free(niz1);
		free(presj_sort);
	}

	int *presj_sort2;
	n2 = 30000;
	niz2 = generiraj(n2);
	for (i = 10000; i <= 50000; i += 5000) {
		niz1 = generiraj(i);
		shuffle(niz1, i);
		pocetak = clock();
		qsort(niz2, n2, sizeof(int), bsu);
		presj_sort2 = presjek_sortiran(niz1, n1, niz2, n2);
		kraj = clock();
		ukupno_vrijeme = ((double)(kraj - pocetak) / CLOCKS_PER_SEC);
		printf("presjek nesortiranog i sortiranog niza sa qsort() (%d): %f\n", i, ukupno_vrijeme);
		free(niz1);
		free(presj_sort2);
	}

	free(niz2);
	return 0;
}
