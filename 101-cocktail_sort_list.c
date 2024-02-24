#include "sort.h"

/**
 * swap - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node: pointer to the node to swap
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	listint_t *prev, *next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*list = next;
	node->prev = next;
	node->next = next->next;
	next->prev = prev;
	next->next = node;
	if (node->next)
		node->next->prev = node;
	if (next->next)
		next->next->prev = next;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (!list || !*list)
		return;

	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current->next; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap(list, current);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; current->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	}
}
