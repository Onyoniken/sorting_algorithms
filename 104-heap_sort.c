#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - main function
 * @array: param 1
 * @size: param 2
 * @base: param 3.
 * @root: param 4
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, g;

	l = 2 * root + 1;
	r = 2 * root + 2;
	g = root;

	if (l < base && array[l] > array[g])
		g = l;
	if (r < base && array[r] > array[g])
		g = r;

	if (g != root)
	{
		swap_ints(array + root, array + g);
		print_array(array, size);
		max_heapify(array, size, base, g);
	}
}

/**
 * heap_sort - main function
 * @array: An array
 * @size: size of the array.
 *
 * Description: implements sdf
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		max_heapify(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_ints(array, array + k);
		print_array(array, size);
		max_heapify(array, size, k, 0);
	}
}
