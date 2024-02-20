#include "sort.h"

/**
 * swapNodes - swaps two nodes in a doubly linked list
 * @first: first node
 * @sec: second node
 */
void swapNodes(listint_t *first, listint_t *sec)
{
	listint_t *temp = NULL;

	if (first->prev != NULL)
	{
		first->prev->next = sec;
	}
	if (sec->next != NULL)
	{
		sec->next->prev = first;
	}
	temp = sec->next;
	sec->next = first;
	first->next = temp;
	temp = first->prev;
	first->prev = sec;
	sec->prev = temp;

}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL;
	listint_t *j = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	i = (*list)->next;

	while (i)
	{
		if (i->n > i->prev->n)
		{
			i = i->next;
			continue;
		}
		else
		{
			j = i;
			i = i->next;

			while (j && j->prev)
			{
				if (j->n < j->prev->n)
				{
					swapNodes(j->prev, j);
					if (j->prev == NULL)
					{
						*list = j;
					}
					print_list(*list);
				}

				else
				{
					j = j->prev;
				}
			}
		}
	}
}
