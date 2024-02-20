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
 * max_heapify - Maintains the max heap property
 * @array: The array to be sorted
 * @size: The size of the array
 * @curr_node: The current node to be heapified
 * @array_size: The size of the whole original array needed for printing
 * Description: This function maintains the max heap property
 * by calling itself recursively on the children of the current node
 * if the current node is less than any of its children
 * it swaps the current node with the largest child
 * and calls itself recursively on the new node
 */
void max_heapify(int *array, size_t size, int curr_node, size_t array_size)
{
	int largest_node = curr_node;
	int left_node = 2 * curr_node + 1;
	int right_node = 2 * curr_node + 2;

	/*left < size to donot violate the idx*/
	if (left_node < (int)size && array[left_node] > array[largest_node])
	{
		largest_node = left_node;
	}

	if (right_node < (int)size && array[right_node] > array[largest_node])
	{
		largest_node = right_node;
	}

	if (largest_node != curr_node)
	{
		swap(&array[curr_node], &array[largest_node]);
		print_array(array, array_size);
		/*recusive call max_heapify on the new node largest now to call its childrn*/
		max_heapify(array, size, largest_node, array_size);
	}
}

/**
 * build_max_heap - Builds a max heap from an array
 * @array: The array to be sorted
 * @size: The size of the array
 * @array_size: The size of the whole original array needed for printing
 * Description: This function builds a max heap from an array
 * calling max_heapify on the first node that has children
 */
void build_max_heap(int *array, size_t size, size_t array_size)
{
	int i = 0;

	for (i = size / 2 - 1; i >= 0; --i)
	{
		max_heapify(array, size, i, array_size);
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Description: This function sorts an array of integers using the heap sort
 * in case of null or size less than 2, do nothing
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	build_max_heap(array, size, size);

	/*Sorting swaping the first and last always then heafipy*/
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		max_heapify(array, i, 0, size);
	}
}
