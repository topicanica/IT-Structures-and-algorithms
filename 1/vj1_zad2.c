#include<stdio.h>
#include<stdlib.h>

int *filtriraj(int *niz, int n, int th, int *nth)
{
	int br = 0;
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
			br++;
	}
	*nth = br;
	int *novi = (int*)malloc(br * sizeof(int));
	for (i = 0; i < n; i++) {
		if (niz[i] < th) {
			novi[j++] = niz[i];
		}
	}
	return novi;
}
int main()
{
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(niz) / sizeof(int);
	int i;
	int nth;
	int th = 7;
	int *filtrirani = filtriraj(niz, n, th, &nth);
	for (i = 0; i < nth; i++)
		printf("%d ", filtrirani[i]);
	getchar();
	return 0;
	
}
