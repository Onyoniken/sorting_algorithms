#include "sort.h"

/**
 * swap_ints - main parameter
 * @a: param 1
 * @b: param 2
 */
void swap_ints(int *a, int *b)
{
	int kb;

	kb = *a;
	*a = *b;
	*b = kb;
}

/**
 * bubble_sort - main function
 * @array: param 1
 * @size: param 2
 *
 * Description: array printer
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (k = 0; k < len - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_ints(array + k, array + k + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
