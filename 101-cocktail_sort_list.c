#include "sort.h"

/**
 * swapTwoNodess - a funciton to swap a node and its next
 * @first: the first node to be replaced with its next
 */
void swapTwoNodess(listint_t *first)
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
	next_next = next->next;

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
 * @new_start: the node to change with its next
 * @list: the list we are sorting
 * @end: the end of the list
 * @start: the start of the list
 * @swapped: bool to the swap
 */
void enterchange(listint_t **new_start, listint_t ***list,
		listint_t **end, listint_t **start, char *swapped)
{
	if ((*new_start)->next == *end)
		*end = *new_start;

	if (*new_start == *start)
	{
		if (!(*new_start)->prev)
		{
			**list = (*new_start)->next;
		}
		*start = (*new_start)->next;
	}

	swapTwoNodess(*new_start);
	*new_start = (*new_start)->prev;
	*swapped = 1;
	print_list(**list);
}

/**
 * cocktail_sort_list - a funciton to sort using cocktail bubble Invariant
 * @list: a double pointer to the list should be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL, *new_start = NULL, *new_end = NULL;
	char swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	for (end = *list; end->next; end = end->next)
		;
	while (swapped)
	{
		swapped = 0;
		for (new_start = start; new_start != end; new_start = new_start->next)
			if (new_start->n > new_start->next->n)
				enterchange(&new_start, &list, &end, &start, &swapped);

		end = end->prev;
		if (!swapped)
			break;
		swapped = 0;
		for (new_end = end->prev; new_end != start->prev; new_end = new_end->prev)
		{
			if (new_end->n > new_end->next->n)
			{
				if (new_end->next == end)
					end = new_end;
				if (new_end == start)
				{
					if (!new_end->prev)
						*list = new_end->next;
					start = new_end->next;
				}
				swapTwoNodess(new_end);
				new_end = new_end->prev;
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
