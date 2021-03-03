#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	float x, y;
}Tocka;

typedef struct
{
	Tocka vrhovi[10];
	int n;

}Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n)
{
	Poligon *np;
	np = (Poligon*)malloc(sizeof(Poligon));
	np->n = n;
	int i;
	for (i = 0; i < n; i++)
	{
		np->vrhovi[i].x = niz_x[i];
		np->vrhovi[i].y = niz_y[i];
	}
	return np;
}
Tocka** pozitivni(Poligon *p, int *np)
{
	*np = 0;
	int i;
	for (i = 0; i < p->n; i++){
        if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
			(*np)++;
    }
	Tocka** poz = (Tocka**)malloc((*np) * sizeof(Tocka));
	*np = 0;
	for (int i = 0; i < p->n; i++)
	{
	    if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
		{
			poz[*np] = &(p->vrhovi[i]);
			(*np)++;
		}
	}
	return poz;
}

int main(void)
{
    float niz_x[] = { 2.0, -1.0, 5.0, 12 };
	float niz_y[] = { -2.0, 3.0, 7.0, -6 };
	int n = sizeof(niz_x) / sizeof(int);
	Poligon *novi_pol;
	novi_pol = novi_poligon(niz_x, niz_y, n);
	for (int i = 0; i < n; i++)
	{
		printf("Tocka %d: (%.2f, %.2f)\n", i+1, novi_pol->vrhovi[i].x, novi_pol->vrhovi[i].y);
	}
	int np;
	Tocka **pozit = pozitivni(novi_pol, &np);
	for (int i = 0; i < np; i++)
	{
        printf("Tocka (%.2f, %.2f)\n", pozit[i]->x, pozit[i]->y);
	}
	getchar();
	return 0;
}
