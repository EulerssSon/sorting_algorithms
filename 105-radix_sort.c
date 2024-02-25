#include "sort.h"

/**
 * free_setNULL - frees a pointer and sets it to NULL
 * @ptr: pointer to free
 * Return: void
 */
void free_setNULL(int **ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	free(*ptr);
	*ptr = NULL;
}

/**
 * find_max - finds the maximum value in an array
 * @arr: array to search
 * @size: size of the array
 * Return: maximum value in the array
 */
int find_max(int *arr, int size)
{
	int max = arr[0];
	int i = 1;

	for (; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return (max);

}

/**
 * count_digits - counts the number of digits in a number
 * @num: number to count digits
 * Return: number of digits
 */
int count_digits(int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}

	while (num > 0)
	{
		num /= 10;
		count++;
	}

	return (count);
}


/**
 * radix_sort_impl - sorts an array of integers
 * uisng radix sort counting on count sort
 * @arr: array to sort
 * @size: size of the array
 * @exp: exponent
 * Return: void
 */
void radix_sort_impl(int *arr, int size, int exp)
{
	int *freq = NULL;
	int *prefix = NULL;
	int *output = NULL;
	int i = 0;

	freq = malloc(sizeof(int) * 10);
	if (freq == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(freq);
		return;
	}

	for (i = 0; i < 10; ++i)
		freq[i] = 0;
	for (i = 0; i < size; ++i)
		++freq[(arr[i] / exp) % 10];
	for (i = 1; i < 10; ++i)
		freq[i] = freq[i] + freq[i - 1];

	prefix = freq;

	for (i = size - 1; i >= 0; --i)
	{
		output[prefix[arr[i] / exp % 10] - 1] = arr[i];
		--prefix[arr[i] / exp % 10];
	}
	for (i = 0; i < size; ++i)
	{
		arr[i] = output[i];
	}

	free_setNULL(&prefix);
	free_setNULL(&output);
}
/**
 * radix_sort - sorts an array helper func
 * that uses count sort algo
 * @arr: array to sort
 * @size: size of the array
 */
void radix_sort(int *arr, size_t size)
{
	int max = 0;
	int digits = 0;
	int i = 0;
	int j = 1;

	if (arr == NULL || size < 2)
	{
		return;
	}
	max = find_max(arr, size);
	digits = count_digits(max);

	for (i = 0; i < digits; ++i)
	{
		radix_sort_impl(arr, (int)size, j);
		print_array(arr, size);
		j *= 10;
	}
}
