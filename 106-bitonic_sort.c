#include "sort.h"

/**
 * bitonic_merge - merges two subarrays in a bitonic sequence
 * @array: array of integers
 * @low: low index
 * @size: size of the array
 * @dir: direction
 * Return: void
 */
void bitonic_merge(int *array, int low, int size, int dir)
{
	int k = 0;
	int temp = 0;
	int i = low;

	if (size > 1)
	{
		k = size / 2;
		for (i = low; i < low + k; ++i)
		{
			if (dir == (array[i] > array[i + k]))
			{

				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;

			}

		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_helper - helper function for bitonic sort
 * @array: array of integers
 * @low: low index
 * @size: size of the array
 * @dir: direction
 * Return: void
 */
void bitonic_sort_helper(int *array, int low, int size, int dir)
{
	int mid = 0;

	if (size > 1)
	{
		printf("Merging [%d/%d] (%s):\n", size, (int)size, dir ? "UP" : "DOWN");
		print_array(array + low, size);
		mid = size / 2;
		bitonic_sort_helper(array, low, mid, 1);
		bitonic_sort_helper(array, low + mid, mid, 0);
		bitonic_merge(array, low, size, dir);

		printf("Result [%d/%d] (%s):\n", size, (int)size, dir ? "UP" : "DOWN");
		print_array(array + low, size);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the Bito
 * sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitonic_sort_helper(array, 0, (int)size, 1);
}
