#include <stdio.h>
#include <malloc.h>
#include "bstree.h"
#include <string.h>

BSTree NewBSTree()
{
	// Novo prazno stablo
	Node *tr = NULL;
	return tr;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if (*bst == NULL)
	{
		(*bst) = (Node*)malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else
	{
		if (strcmp(word, (*bst)->word) < 0)
		{
			AddNode((&(*bst)->left), word);
		}
		else if (strcmp(word, (*bst)->word) > 0)
		{
			AddNode((&(*bst)->right), word);
		}
		
		else
		{
			free(word);
		}
	}
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	int lijevo = 0, desno = 0;
	if (bst == NULL)
		return 0;
	lijevo = BSTHeight(bst->left);
	desno = BSTHeight(bst->right);
	if (lijevo < desno)
		return 1 + desno;
	else
		return 1 + lijevo;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if (bst == NULL)
		return;
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().
	char rijec[1024];
	Node *bst = NewBSTree();
	while (fscanf(fd, "%s ", rijec) != EOF)
	{
		AddNode(&bst, strdup(rijec));
	}
	return bst;
}
int Rijeci(BSTree bst)
{
	if (bst == NULL)
		return 0;
	if (strlen(bst->word) > 5)
		return Rijeci(bst->right)+ Rijeci(bst->left) + 1;
	if (strlen(bst->word) <= 5)
		return Rijeci(bst->right)+ Rijeci(bst->left);
}