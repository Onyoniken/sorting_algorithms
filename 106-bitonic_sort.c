#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - main function
 * @array: param 1
 * @size: param 2
 * @start: param 3
 * @seq: param 4
 * @flow: param 5
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t k, j = seq / 2;

	if (seq > 1)
	{
		for (k = start; k < start + j; k++)
		{
			if ((flow == UP && array[k] > array[k + j]) ||
			    (flow == DOWN && array[k] < array[k + j]))
				swap_ints(array + k, array + k + j);
		}
		bitonic_merge(array, size, start, j, flow);
		bitonic_merge(array, size, start + j, j, flow);
	}
}

/**
 * bitonic_seq - main function
 * @array: param 1
 * @size: param 2
 * @start: param 3
 * @seq: param 4
 * @flow: param 5
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t c = seq / 2;
	char *s = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, s);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, c, UP);
		bitonic_seq(array, size, start + c, c, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, s);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - main function
 * @array: param 1
 * @size: param 2
 *
 * Description: prints array after swap
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
