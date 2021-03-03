#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	float x, y, z;
}Vrh;
typedef struct
{
	Vrh n, v1, v2, v3;
	unsigned short b;
}Trokut;
typedef struct
{
	Trokut *nizt;
	int brt;
}Objekt3D;

Objekt3D *readbin(FILE *fd)
{
	Objekt3D *bin = (Objekt3D*)malloc(sizeof(Objekt3D));
	fseek(fd, 80, SEEK_SET);
	int brt,i;
	fread(&brt, 4, 1, fd);
	Trokut *niz_tr = (Trokut*)malloc(brt * sizeof(Trokut));
	for (i = 0; i < brt; i++)
	{
		fread(&(niz_tr[i]), 50, 1, fd);
	}
	bin->nizt = niz_tr;
	bin->brt = brt;
	return bin;
}
void writebin(Objekt3D *bin, FILE *nfd)
{
	char buffer[80] = { 0 };
	fwrite(buffer, 1, 80, nfd);
	fwrite(&(bin->brt), 4, 1, nfd);
	for (int i=0;i<bin->brt;i++)
	{
		fwrite(&(bin->nizt[i]), 50, 1, nfd);
	}
}
void writetxt(Objekt3D *bin, FILE *nfd2)
{
	fprintf(nfd2, "%s\n", "solid");
	int i;
	for (i = 0; i < bin->brt; i++)
	{
		fprintf(nfd2, "%s %f %f %f\n", "  facet normal", bin->nizt[i].n.x, bin->nizt[i].n.y, bin->nizt[i].n.z);
		fprintf(nfd2, "%s\n", "    outer loop");
		fprintf(nfd2, "%s %f %f %f\n", "      vertex", bin->nizt[i].v1.x, bin->nizt[i].v1.y, bin->nizt[i].v1.z);
		fprintf(nfd2, "%s %f %f %f\n", "      vertex", bin->nizt[i].v2.x, bin->nizt[i].v2.y, bin->nizt[i].v2.z);
		fprintf(nfd2, "%s %f %f %f\n", "      vertex", bin->nizt[i].v3.x, bin->nizt[i].v3.y, bin->nizt[i].v3.z);
		fprintf(nfd2, "%s\n", "    endloop");
		fprintf(nfd2, "%s\n", "  endfacet");

	}
	fprintf(nfd2, "%s\n", "endsolid");
}
void destroy(Objekt3D *bin)
{
	free(bin->nizt);
	free(bin);
}
int main(void)
{
	FILE *fd = fopen("primjerbin.stl", "rb");
	Objekt3D *bin = readbin(fd);
	fflush(fd);
	fclose(fd);
	FILE *nfd = fopen("novabin.stl", "wb");
	writebin(bin, nfd);
	fflush(nfd);
	fclose(nfd);
	FILE *nfd2 = fopen("novatxt.stl", "wt");
	writebin(bin,nfd2);
	fflush(nfd2);
	fclose(nfd2);
	destroy(bin);
	return 0;
}
