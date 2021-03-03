#include<stdio.h>
#include<ctype.h>
#include<string.h>

int mystrlen(char *string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}
char *mystrcpy(char *string1, char *string2)
{
	int i = 0;
	while (string2[i] != '\0')
	{
		string1[i] = string2[i];
		i++;
	}
	string1[i] = '\0';
	return string1;
}
int mystrcmp(char *string1, char *string2)
{
	int i = 0;

	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			break;
		}
		i++;
	}
	if (string1[i] < string2[i])
	{
		return -1;
	}
	else if (string1[i] > string2[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char *mystrcat(char *string1, char *string2)
{
	int i, j;
	for (i = 0; string1[i]; i++);
	for (j = 0; string2[j]; j++, i++)
		string1[i] = string2[j];
	string1[i] = '\0';
	return string1;

}
char *mystrstr(char *string1, char *string2)
{
    int i=0, j=0;
    while(string1[i]!='\0')
    {
        j=0;
        while(string1[i+j]==string2[j])
        {
            j++;
            if(string2[j]=='\0')
                return &string1[i];
        }
        i++;
    }
    return NULL;
}
char *reverse(char *string1, char *string2)
{
	int i = 0;
	int j = strlen(string2) - 1;
	while (j >= 0)
	{
		string1[i++] = string2[j--];
	}
	string1[i] = '\0';
	return string1;
}
int main(void)
{
	char str1[] = "test za funkciju";
    char str2[] = "drugi string test";

    // mystrlen
    printf("mystrlen: duljina stringa '%s': %d\n\n", str1, mystrlen(str1));

    // mystrcpy
    char *novistr_cpy = mystrcpy(str1, str2);
    printf("mystrcpy: %s\n\n", novistr_cpy);

    // mystrcmp
	char str5[] = "eibc";
	char str6[] = "eabc";
	printf("mystrcmp: %d\n\n", mystrcmp(str5, str6));

    char str3[] = "string za strcat";
    char str4[] = "drugi string ";

    // mystrcat
    printf("mystrcat: %s\n\n", mystrcat(str3, str4));

    char str52[] = "abc ef de defd";
	char str62[] = "def";
    // mystrstr
	char *pmystrstr = mystrstr(str52, str62);
	printf("mystrstr: %p - %c\n\n", pmystrstr, *pmystrstr);

    // reverse
    char str7[] = "test trece fun";
    char str8[] = "naopako";
    char *testzareverse = reverse(str7, str8);
    printf("reverse: %s\n\n", testzareverse);

    return 0;
}
