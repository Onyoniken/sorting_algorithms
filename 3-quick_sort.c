#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - main function that swaps int.
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
 * lomuto_partition - main function
 * @array: array
 * @size: size
 * @left: starts from left
 * @right: ends in the right
 *
 * Return: final index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *p, a, b;

	p = array + right;
	for (a = b = left; b < right; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}

	return (a);
}

/**
 * lomuto_sort - main param
 * @array: array
 * @size: size
 * @left: starting point
 * @right: ending point
 *
 * Description: lamunto scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - main function
 * @array: param 1
 * @size: param 2
 *
 * Description: lamumto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
