#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 * Description: This function swaps the values of two integers
 * in case of null or same value, do nothing
 */
void swap(int *a, int *b)
{
	int t = 0;

	if (a == NULL || b == NULL || *a == *b)
	{
		return;
	}
	t = *a;
	*a = *b;
	*b = t;
}

/**
 * partion - Partions an array using the Lomuto scheme
 * @array: The array to be sorted
 * @left: The left index of the array the start of the partition
 * @right: The right index of the array the end of the partition
 * @size: The size of the whole original array needed for printing
 * Description: This function takes the last element of the array as the pivot
 * and places all elements smaller than the pivot to the left of the pivot
 * and all elements greater than the pivot to the right of the pivot
 * Return: The index of the pivot after the partition
 */
size_t partion(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left;
	int j = left;

	for (; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != right)
	{
		swap(&array[i], &array[right]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_helper - Sorts an array of integers using the quick sort alg
 * @array: The array to be sorted
 * @left: The left index of the array
 * @right: The right index of the array
 * @size: The size of the whole original array needed for printing
 * Description: This function sorts an array of integers using the quick sort
 */
void quick_sort_helper(int *array, int left, int right, int size)
{
	size_t part = 0;

	if (left < right)
	{
		part = partion(array, left, right, size);
		quick_sort_helper(array, left, part - 1, size);
		quick_sort_helper(array, part + 1, right, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Description: This function sorts an array of integers using the quick sort
 * in case of null or size less than 2, do nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
