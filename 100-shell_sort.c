#include "sort.h"

/**
 * swap_ints - main function
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
 * shell_sort - main function
 * @array: array.
 * @size: size
 *
 * Description: checks interva seq
 */
void shell_sort(int *array, size_t size)
{
	size_t g, k, l;

	if (array == NULL || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (k = g; k < size; k++)
		{
			l = k;
			while (l >= g && array[l - g] > array[l])
			{
				swap_ints(array + l, array + (l - g));
				l -= g;
			}
		}
		print_array(array, size);
	}
}
