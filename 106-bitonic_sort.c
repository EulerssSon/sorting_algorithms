#include "sort.h"
#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - merges two subarrays of a bitonic sequence in ascending
 * order
 * @array: array to sort
 * @size: size of the array
 * @dir: direction of the sort
 * @start: start index of the subarray
 * @end: end index of the subarray
 */
void bitonic_merge(int *array, size_t size, int dir, size_t start, size_t end)
{
	size_t i, step;

	if (end - start < 2)
		return;

	step = (end - start) / 2;
	for (i = start; i < start + step; i++)
	{
		if (dir == (array[i] > array[i + step]))
		{
			swap(&array[i], &array[i + step]);
		}
	}
	bitonic_merge(array, size, dir, start, start + step);
	bitonic_merge(array, size, dir, start + step, end);
}

/**
 * bitonic_sort_recursive - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @dir: direction of the sort
 * @size: size of the array
 * @size_arr: the size of the whole arr needed for printintg
 */
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t size_arr)
{
	size_t k;

	if (size < 2)
		return;

	k = size / 2;
	printf("Merging [%lu/%lu] (%s):\n", size, size_arr, dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sort_recursive(array, k, 1, size_arr);
	bitonic_sort_recursive(array + k, k, 0, size_arr);
	bitonic_merge(array, size, dir, 0, size);
	printf("Result [%lu/%lu] (%s):\n", size, size, dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1, size);
}

