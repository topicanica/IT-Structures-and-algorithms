#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

int readWord(FILE *fd, char *buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE *fd;
	char buffer[1024];
	Dictionary dict;

	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		add(dict, buffer);
	}

	Dictionary filtriran = filterDictionary(dict, filter);
	print(filtriran);

	//print(dict);
	destroy(filtriran);


	fclose(fd);


}