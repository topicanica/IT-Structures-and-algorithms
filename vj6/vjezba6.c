#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int prioritet;
	void *podatak;
}Element;

typedef struct {
	Element *niz;
	int n;
}Gomila;

void zamjena(Element *a, Element *b)
{
	Element tmp = *a;
	*a = *b;
	*b = tmp;
}
void prema_vrhu(int c, Gomila *red)
{
	if (c == 0)
		return;
	int r = (c - 1) / 2;
	if (red->niz[r].prioritet < red->niz[c].prioritet)
	{
		zamjena(&(red->niz[r]), &(red->niz[c]));
		prema_vrhu(r, red);
	}
}
void na_kraj(Gomila *red, int *p, void *pod)
{
	int n = red->n;
	red->niz[n].prioritet = p;
	red->niz->podatak = pod;
	prema_vrhu(n,red);
	red->n++;
}
void ukloni_s_vrha(Gomila *red)
{
	red->n--;
	int n = red->n;
	red->niz[0] = red->niz[n];
	prema_vrhu(0, red);
}
void prema_dnu(Gomila *red, int r)
{
	int l = 2 * r - 1;
	int d = 2 * r - 2;
	
	if (red->niz[r].prioritet < red->niz[l].prioritet || red->niz[r].prioritet < red->niz[d].prioritet)
	{
		if (red->niz[l].prioritet > red->niz[d].prioritet)
		{
			zamjena(&(red->niz[r]), &(red->niz[l]));
			prema_dnu(red, l);
		}
		else {
			zamjena(&(red->niz[r]), &(red->niz[d]));
			prema_dnu(red, d);
		}
	}
}
int main()
{
	Gomila *red;
	red = malloc(sizeof(Gomila));
	int n = 1000;
	red->n = 0;
	red->niz = malloc(n * sizeof(Element));
	
	int a, b, c, d, e, f, g, h, i, j;
	a = 60;
	b = 80;
	c = 85;
	d = 25;
	e = 70;
	f = 30;
	g = 50;
	h = 23;
	i = 10;
	j = 20;

	void *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8, *d9, *d10;
	d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = d10 = NULL;

	na_kraj(red, a, d1);
	na_kraj(red, b, d2);
	na_kraj(red, c, d3);
	na_kraj(red, d, d4);
	na_kraj(red, e, d5);
	na_kraj(red, f, d6);
	na_kraj(red, g, d7);
	na_kraj(red, h, d8);
	na_kraj(red, i, d9);
	na_kraj(red, j, d10);

	for (i = 0; i < red->n;i++)
	{
		printf("%d ", red->niz[i].prioritet);
	}
	printf("\n\n");
	
	ukloni_s_vrha(red);

	for (i = 0; i < red->n; i++)
	{
		printf("%d ", red->niz[i].prioritet);
	}
	printf("\n\n");
}
