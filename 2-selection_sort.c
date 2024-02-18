#include "sort.h"

/**
 * swap - swap two ints
 * using pointers in case of null return
 * @first: first int ptr
 * @second: seond int ptr
 */
void swap(int *first, int *second)
{
	int temp;

	if (first == NULL || second == NULL)
	{
		return;
	}
	if (*first == *second)
	{
		return;
	}
	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using swaping sublists in min idx to the left
 * @array: array of integers
 * @size: size of the array
 * using swaping sublists in min idx to the left
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	size_t min_index = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
