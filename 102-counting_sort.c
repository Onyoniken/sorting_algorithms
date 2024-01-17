#include "sort.h"

/**
 * get_max - main function
 * @array: An array.
 * @size: The size of array.
 *
 * Return: max array
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
 * counting_sort - main function
 * @array: Array
 * @size: size of array.
 *
 * Description: Prints array
 */
void counting_sort(int *array, size_t size)
{
	int *c, *s, m, k;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	m = get_max(array, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(s);
		return;
	}

	for (k = 0; k < (m + 1); k++)
		c[k] = 0;
	for (k = 0; k < (int)size; k++)
		c[array[k]] += 1;
	for (k = 0; k < (m + 1); k++)
		c[k] += c[k - 1];
	print_array(c, m + 1);

	for (k = 0; k < (int)size; k++)
	{
		s[c[array[k]] - 1] = array[k];
		c[array[k]] -= 1;
	}

	for (k = 0; k < (int)size; k++)
		array[k] = s[k];

	free(s);
	free(c);
}
