#include <stdio.h>
#include "sort.h"

/**
 * print_list - main function
 *
 * @list: parameter to print list
 */
void print_list(const listint_t *list)
{
	int k;

	k = 0;
	while (list)
	{
		if (k > 0)
			printf(", ");
		printf("%d", list->n);
		++k;
		list = list->next;
	}
	printf("\n");
}
