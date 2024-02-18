#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0, max = 0;
	int *freq = NULL, *cpy_freq = NULL;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; ++i)
		if ((size_t)array[i] > max)
			max = array[i];
	freq = malloc(sizeof(int) * (max + 1));
	if (freq == NULL)
		return;
	cpy_freq = malloc(sizeof(int) * (max + 1));
	if (cpy_freq == NULL)
	{
		free(freq);
		return;
	}
	for (i = 0; i < max + 1; ++i)
	{
		freq[i] = 0;
		cpy_freq[i] = 0;
	}
	for (i = 0; i < size; ++i)
	{
		++cpy_freq[array[i]];
		++freq[array[i]];
	}
	for (i = 0; i < max + 1; ++i)
	{
		if (i > 0)
			freq[i] += freq[i - 1];
	}
	print_array(freq, max + 1);
	for (i = 0; i < max + 1; ++i)
		if (cpy_freq[i] > 0)
			for (j = 0; j < (size_t)cpy_freq[i]; ++j)
				array[k++] = i;
	free(freq);
	free(cpy_freq);
}
