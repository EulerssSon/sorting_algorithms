#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
/**
 * swap - Swaps 2 ints
 *
 * @first: first int Ptr
 * @second: second int Ptr
 */
void swap(int *first, int *second)
{
	int temp = *first;
	*second = *first;
	*first = temp;
}
