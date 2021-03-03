#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"


Dictionary create() {
	Dictionary novi;
	novi = (Dictionary)malloc(sizeof(Word));
	novi->word = NULL;
	novi->count = 0;
	novi->next = NULL;
	return novi;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str) {
	Dictionary prev = dict;
	Dictionary curr = dict->next;

	Dictionary tmp = NULL;

	// Ako je lista prazna dodaj rijec i postavi broj pojavljivanja na 1
	if (curr == NULL) {
		tmp = create();
		tmp->word = strdup(str);
		tmp->count++;
		prev->next = tmp;
		return;
	}

	while (curr != NULL) {
		// Ako postoji str u listi povecaj broj pojavljivanja (count) za 1
		if (strcmp(str, curr->word) == 0) {
			curr->count++;
			return;
		}
		// S obzirom da je lista sortirana
		else if (strcmp(str, curr->word) < 0) {
			tmp = create();
			tmp->word = strdup(str);
			tmp->count++;
			tmp->next = curr;
			prev->next = tmp;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	// Ako nema rijeci u listi ili je veca od svih unutra
	// Dodaj rijec na kraj
	tmp = create();
	tmp->word = strdup(str);
	tmp->count++;
	prev->next = tmp;
}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict) {
	Dictionary s = dict->next;
	while (s != NULL) {
		printf("%s \t(%d)\n", s->word, s->count);
		s = s->next;
	}
	printf("\n");
}

// briše cijeli rjeènik
void destroy(Dictionary dict) {
	Dictionary s = dict->next;
	while (s != NULL) {
		Dictionary brisi = s;
		s = s->next;
		free(brisi->word);
		free(brisi);
	}
}

int filter(Word *w) {
	if (w == NULL) {
		return 0;
	}
	if (w->count > 5 && w->count < 10 && strlen(w->word) > 3) {
		return 1;
	}
	return 0;
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word *w)) {
	Dictionary prev = indict;
	Dictionary curr = indict->next;

	while (curr != NULL) {

		if (filter(curr) == 0) { // ne odgovara uvjetu filtera
			Dictionary brisi = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(brisi->word);
			free(brisi);
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	return indict;
}
