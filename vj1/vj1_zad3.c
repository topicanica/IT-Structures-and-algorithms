#include<stdio.h>
#include<stdlib.h>

int **podijeli(int *niz, int n)
{
	int dulj = n / 2;
	int **pniz = (int**)malloc(2 * sizeof(int*));

	pniz[0] = (int*)malloc(dulj * sizeof(int));
	pniz[1] = (int*)malloc((n - dulj)* sizeof(int));

	int i;
	for (i = 0; i < dulj; i++)
	{
		pniz[0][i] = niz[i];
		pniz[1][i] = niz[i + dulj];
	}
	if (n % 2 == 1)
		pniz[1][i] = niz[i + dulj];
	return pniz;
}
int main(void)
{
	int niz[] = { 1,2,3,4,5,6,7,8};
	int n = sizeof(niz) / sizeof(int);
	int i;
	int **podjeljeni;
	podjeljeni = podijeli(niz,n);
	for (i = 0; i < n / 2; i++)
	{
		printf("prvi dio: %d drugi dio: %d\n", podjeljeni[0][i], podjeljeni[1][i]);
	}
	if (n % 2 == 1)
		printf("drugi dio: %d\n", podjeljeni[1][i]);
	getchar();
	return 0;
}