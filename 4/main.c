#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sortiranja.h"

int main(void)
{
	choose_pivot = 1;
	n_min = 0;
	srand(time(NULL));
	
	int *prvi, *drugi;
	int dulj1 = 8000;
	int dulj2 = 8000;
	prvi = generate(dulj1);
	drugi = generate(dulj2);
	printf("quicksort nesortirani %f\n", measure(quicksort, prvi, dulj1));
	printf("quicksort sortirani %f\n", measure(quicksort, prvi, dulj1));
	printf("quicksort pivot nesortirani %f\n", measure(quicksort_pivot, drugi, dulj2));
	printf("quicksort pivot sortirani %f\n", measure(quicksort_pivot, drugi, dulj2));
	free(drugi);

	dulj1 = 1000000;
	for (n_min = 0; n_min < 200; n_min += 2)
	{
		prvi = generate(dulj1);
		printf("vrijeme (qsort sel) %f\n", measure(quicksort_sel, prvi, dulj1));
		printf("\n");
		free(prvi);
	}
	for (n_min = 0; n_min < 200; n_min += 2)
	{
		prvi = generate(dulj1);
		printf("vrijeme (qsort ins) %f\n", measure(quicksort_ins, prvi, dulj1));
		printf("\n");
		free(prvi);

	}
	

	return 0;
}


