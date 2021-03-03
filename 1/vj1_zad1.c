#include<stdio.h>
#include<stdlib.h>

int *podniz(int *niz, int start, int stop)
{
	int j = 0;
	int duz = stop - start ;
	int *podniz = (int*)malloc(duz * sizeof(int));
	for (int i = start; i < stop +1; i++) {
		podniz[j] = niz[i];
		j++;
	}
	return podniz;
}

int main(void)
{
	int niz[] = {2,3,47,7,5,9,5};
	int start = 4;
	int stop = 6;
	int duzina = stop - start;
	int *novi = podniz(niz, start, stop);
	for (int i = 0; i < duzina; i++)
		printf("%d ", novi[i]);
	getchar();
	return 0;

}