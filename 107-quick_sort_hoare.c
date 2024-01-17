#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - main function
 * @array: param 1
 * @size: param 2
 * @left: param 3.
 * @right: param 4
 *
 * Return: idx
 *
 * Description: pvt swap
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int p, a, b;

	p = array[right];
	for (a = left - 1, b = right + 1; a < b;)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);

		if (a < b)
		{
			swap_ints(array + a, array + b);
			print_array(array, size);
		}
	}

	return (a);
}

/**
 * hoare_sort - main function
 * @array: param 1
 * @size: param 2
 * @left: param 3
 * @right: param 4
 *
 * Description: hhrd descroptor
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - main function
 * @array: param 1
 * @size: param 2
 *
 * Description: hhrd descriptor
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
