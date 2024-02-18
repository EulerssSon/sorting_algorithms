#include "sort.h"

/**
 * merge - Merges two sub-arrays of integers
 * @l_arr: The left sub-array
 * @l_size: Number of elements in @l_arr
 * @r_arr: The right sub-array
 * @r_size: Number of elements in @r_arr
 * Description: Merges two sub-arrays of integers into a single sorted array
 */
void merge(int *l_arr, size_t l_size, int *r_arr, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((l_size + r_size) * sizeof(int));

	if (temp == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(l_arr, l_size);
	printf("[right]: ");
	print_array(r_arr, r_size);
	while (i < l_size && j < r_size)
	{
		if (l_arr[i] < r_arr[j])
		{
			temp[k++] = l_arr[i++];
		}
		else
		{
			temp[k++] = r_arr[j++];
		}
	}
	while (i < l_size)
	{
		temp[k++] = l_arr[i++];
	}
	while (j < r_size)
	{
		temp[k++] = r_arr[j++];
	}
	for (k = 0, i = 0; i < l_size; ++i, ++k)
	{
		l_arr[i] = temp[k];
	}
	for (j = 0; j < r_size; ++j, ++k)
	{
		r_arr[j] = temp[k];
	}
	printf("[Done]: ");
	print_array(temp, l_size + r_size);
	free(temp);
}

/**
 * merge_sort_helper - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Description: Sorts an array of integers in ascending order
 * using the merge sort algorithm
 */
void merge_sort_helper(int *array, size_t size)
{
	size_t half = size / 2;

	if (size <= 1)
	{
		return;
	}

	merge_sort_helper(array, half);
	merge_sort_helper(array + half, size - half);

	merge(array, half, array + half, size - half);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
	{
		return;
	}

	merge_sort_helper(array, size);
}
