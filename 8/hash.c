#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567891

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable *table;
	table = malloc(sizeof(HashTable));
	table->table = calloc(size, sizeof(Bin*));
	table->size = size;
	table->load = 0;
	return table;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int key = hash(word) % ht->size;
	Bin *item = malloc(sizeof(Bin));
	item->word = strdup(word);
	item->next = NULL;

	if (ht->table[key] == NULL) {
		ht->table[key] = item;
		ht->load++;
		return;
	}
	else {
		while (ht->table[key]->next != NULL) {
			ht->table[key]->next = ht->table[key]->next->next;
		}
		ht->table[key]->next = item;
		ht->load++;
	}
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int key = hash(word) % ht->size;
	Bin *p = ht->table[key];
	if (p != NULL) {
		while (p != NULL) {
			if (strcmp(word, p->word) == 0) {
				return 1;
			}
			else {
				p = p->next;
			}
		}
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)

	for (int i = 0; i < ht->size; i++) {
		if (ht->table[i] != NULL) {
			if (ht->table[i]->next == NULL) {
				free(ht->table[i]->word);
				free(ht->table[i]);
			}
			else {
				while (ht->table[i]->next != NULL) {
					Bin *brisi = ht->table[i];
					ht->table[i] = ht->table[i]->next;
					free(brisi->word);
					free(brisi);
				}
			}
		}
	}
	free(ht);
}