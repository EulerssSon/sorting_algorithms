#include "sort.h"

/**
 * swap - swap two ints
 * using pointers in case of null return
 * @a: first int ptr
 * @b: seond int ptr
 */
void swap(int *a, int *b)
{
	int temp;

	if (a == NULL || b == NULL)
		return;
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @arr: array of integers
 * @size: size of the array
 */
void bubble_sort(int *arr, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	if (arr == NULL || size == 0)
	{
		return;
	}

	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; j < size - i - 1; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(&arr[j + 1], &arr[j]);
				print_array(arr, size);
			}
		}
	}
}
