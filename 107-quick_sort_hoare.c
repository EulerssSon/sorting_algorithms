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
 * partion_hoare - Partions an array using the Hoare scheme
 * @array: The array to be sorted
 * @left: The left index of the array the start of the partition
 * @right: The right index of the array the end of the partition
 * @size: The size of the whole original array needed for printing
 * Description: This function takes the first element of the array as the pivot
 * and places all elements smaller than the pivot to the left of the pivot
 * and all elements greater than the pivot to the right of the pivot
 * Return: The index of the pivot after the partition
*/
int partion_hoare(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	int j = right + 1;

	/* Partition the array */
	while (i < j)
	{
		/* Find element on the left greater than or equal to pivot */
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * quick_sort_helper_hoare - Sorts an array of ints using quick sort
 * by the Hoare scheme
 * @array: The array to be sorted
 * @left: The left index of the array
 * @right: The right index of the array
 * @size: The size of the whole original array needed for printing
 */
void quick_sort_helper_hoare(int *array, int left, int right, int size)
{
	int part = 0;

	if (left < right)
	{
		part = partion_hoare(array, left, right, size);
		quick_sort_helper_hoare(array, left, part - 1, size);
		quick_sort_helper_hoare(array, part, right, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers using the quick sort algorithm
 * by the Hoare scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper_hoare(array, 0, size - 1, size);
}
