#include "sort.h"

/**
 * swap_ints - main swapping function
 * @a: parameter 1
 * @b: parameter 2
 */
void swap_ints(int *a, int *b)
{
	int kb;

	kb = *a;
	*a = *b;
	*b = kb;
}

/**
 * selection_sort - main selection function
 * @array: param 1
 * @size: param 2
 *
 * Description: prints after swap.
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t k, l;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		m = array + k;
		for (l = k + 1; l < size; l++)
			m = (array[l] < *m) ? (array + l) : m;

		if ((array + k) != m)
		{
			swap_ints(array + k, m);
			print_array(array, size);
		}
	}
}
