#include "sort.h"

/**
 * swapTwoNodes - a funciton to swap a node and its next
 * @first: the first node to be replaced with its next
 */

void swapTwoNodes(listint_t *first)
{
	listint_t *prev = NULL;
	listint_t *next = first->next;
	listint_t *next_next = NULL;

	if (!next)
		return;

	if (first->prev)
	{
		prev = first->prev;
	}
	if (next)
	{
		next_next = next->next;
	}

	first->next = next->next;
	first->prev = next;
	next->prev = prev;
	next->next = first;

	if (prev)
		prev->next = next;
	if (next_next)
		next_next->prev = first;
}
/**
 * enterchange - a helper function to the sort
 * @new_end: the node to change with its next
 * @list: the list we are sorting
 */
void enterchange(listint_t *new_end, listint_t **list)
{
	if (!new_end->prev)
		*list = new_end->next;
	swapTwoNodes(new_end);
	print_list(*list);
}

/**
 * cocktail_sort_list - a funciton to sort using cocktail bubble Invariant
 * @list: a double pointer to the list should be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL, new_start = NULL, new_end = NULL;
	char swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		for (new_start = start; new_start->next != end; new_start = new_start->next)
		{
			if (new_start->n > new_start->next->n)
			{
				if (!new_start->prev)
					*list = new_start->next;
				swapTwoNodes(new_start);
				new_start = new_start->prev;
				swapped = 1;
				print_list(*list);
			}
		}
		if (!end)
			end = new_start;
		else
			end = end->prev;
		if (!swapped)
			break;
		swapped = 0;
		for (new_end = end->prev; new_end != start->prev && new_end;
				new_end = new_end->prev)
		{
			if (new_end->n > new_end->next->n)
			{
				enterchange(new_end, list);
				new_end = new_end->prev;
				swapped = 1;
			}
		}

		start = start->next;
	}
}

