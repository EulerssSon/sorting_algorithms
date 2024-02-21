#include "sort.h"
/**
 * get_gap - gets the gap for the shell sort algorithm
 * using the Knuth sequence
 * @size: size of the array
 * Return: gap
 */
size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	if (gap >= size)
	{
		gap = (gap - 1) / 3;
	}
	return (gap);
}
/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0;
	size_t i = 0;
	size_t j = 0;
	int temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	gap = get_gap(size);

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; ++i)
		{
			temp = array[i];

			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
