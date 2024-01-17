#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - main function
 * @array: param 1
 * @size: param 2
 *
 * Return: maximum integer
 */
int get_max(int *array, int size)
{
	int m, k;

	for (m = array[0], k = 1; k < size; k++)
	{
		if (array[k] > m)
			m = array[k];
	}

	return (m);
}

/**
 * radix_counting_sort - main function
 * @array: param 1
 * @size: param 2
 * @sig: param 3
 * @buff: param 4
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t k;

	for (k = 0; k < size; k++)
		count[(array[k] / sig) % 10] += 1;

	for (k = 0; k < 10; k++)
		count[k] += count[k - 1];

	for (k = size - 1; (int)k >= 0; k--)
	{
		buff[count[(array[k] / sig) % 10] - 1] = array[k];
		count[(array[k] / sig) % 10] -= 1;
	}

	for (k = 0; k < size; k++)
		array[k] = buff[k];
}

/**
 * radix_sort - main function
 * @array: param 1
 * @size: param 2
 *
 * Description: Implements ppid
 */
void radix_sort(int *array, size_t size)
{
	int m, s, *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	m = get_max(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		radix_counting_sort(array, size, s, b);
		print_array(array, size);
	}

	free(b);
}
