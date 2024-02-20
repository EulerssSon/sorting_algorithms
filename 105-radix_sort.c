#include "sort.h"

/**
 * freq_set_NULL - sets a pointer to NULL and frees the memory
 * @ptr: pointer to a pointer
 * Return: void
 */
void freq_set_NULL(void **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * count_digits - counts the number of digits in an integer
 * @nums: integer
 * Return: number of digits
 */
size_t count_digits(int nums)
{
	size_t count = 0;

	while (nums != 0)
	{
		nums /= 10;
		++count;
	}
	return (count);
}

/**
 * radix_helper - helper function for radix sort
 * make freq arr and prefix sum using hashing of % 10 on the ones place
 * tens place and so on.
 * malloc output array and freq array if case of fail free and return
 * @array: array of integers
 * @size: size of the array
 * @exp: exponent
 */
void radix_helper(int *array, size_t size, int exp)
{
	int *freq;
	int *output;
	int i = 0;

	freq = malloc(sizeof(int) * 10);
	if (freq == NULL)
	{
		return;
	}
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(freq);
		return;
	}
	for (i = 0; i < 10; ++i)
	{
		freq[i] = 0;
	}
	for (i = 0; i < (int)size; ++i)
	{
		++freq[(array[i] / exp) % 10];
	}
	for (i = 1; i < 10; ++i)
	{
		freq[i] += freq[i - 1];
	}
	for (i = (int)size - 1; i >= 0; --i)
	{
		output[freq[(array[i] / exp) % 10] - 1] = array[i];
		--freq[(array[i] / exp) % 10];
	}
	for (i = 0; i < (int)size; ++i)
	{
		array[i] = output[i];
	}

	print_array(array, size);
	freq_set_NULL((void **)&freq);
	freq_set_NULL((void **)&output);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = -2147483647 - 1;
	int i = 1;
	int exp = 1;
	size_t j = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (j = 0; j < size; ++j)
	{
		if (array[j] > max)
		{
			max = array[j];
		}
	}
	max = count_digits(max);

	for (i = 0; i < max; ++i)
	{
		radix_helper(array, size, exp);
		exp *= 10;
	}
}
