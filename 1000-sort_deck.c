#include "deck.h"

/**
 * get_middle - gets the middle of a doubly linked list
 * using slow and fast pointers when fast pointer reaches
 * the end of the list, slow pointer will be at the middle
 * @head: pointer to the head of the list
 * Return: pointer to the middle of the list
 */
deck_node_t *get_middle(deck_node_t *head)
{
	deck_node_t *fast = head;
	deck_node_t *slow = head;

	if (head == NULL)
	{
		return (NULL);
	}

	fast = fast->next;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return (slow);
}
/**
 * compare - compares two cards
 * @card1: pointer to the first card
 * @card2: pointer to the second card
 * Return: 0 if the cards are equal, 1 if the first card is greater
 * than the second, -1 if the first card is less than the second
 * Description: compares two cards by their kind and value
 * if the kind is different, the comparison is made by the kind
 * if the kind is the same, the comparison is made by the value
 * from ace to king from from spades to diamonds
 */
int compare(const card_t *card1, const card_t *card2)
{
	int val1 = 0, val2 = 0;

	if (card1->kind != card2->kind)
		return (card1->kind - card2->kind);

	if (card1->value[0] >= '2' && card1->value[0] <= '9')
		val1 = card1->value[0] - '0';
	else if ((card1->value)[0] == '1')
		val1 = 10;
	else if ((card1->value)[0] == 'J')
		val1 = 11;
	else if ((card1->value)[0] == 'Q')
		val1 = 12;
	else if ((card1->value)[0] == 'K')
		val1 = 13;
	else if ((card1->value)[0] == 'A')
		val1 = 1;

	if (card2->value[0] >= '2' && card2->value[0] <= '9')
		val2 = card2->value[0] - '0';
	else if ((card2->value)[0] == 1)
		val2 = 10;
	else if ((card2->value)[0] == 'J')
		val2 = 11;
	else if ((card2->value)[0] == 'Q')
		val2 = 12;
	else if ((card2->value)[0] == 'K')
		val2 = 13;
	else if ((card2->value)[0] == 'A')
		val2 = 1;

	return (val1 - val2);
}

/**
 * merge_dll - merges two doubly linked lists
 * @left: pointer to the head of the first list
 * @right: pointer to the head of the second list
 * Return: pointer to the head of the merged list
 * Description: merges two doubly linked lists in O(n) time O(1) space
 * using a dummy node to keep track of the merged list
 * editing the pointers of the nodes in the lists
 */
deck_node_t *merge_dll(deck_node_t *left, deck_node_t *right)
{
	deck_node_t *dummy, *save_dummy;

	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	dummy = malloc(sizeof(deck_node_t));
	save_dummy = dummy;
	while (left && right)
	{
		if (compare(left->card, right->card) < 0)
		{
			dummy->next = left;
			dummy->prev = left->prev;
			left->prev = dummy;
			left = left->next;
		}
		else
		{
			dummy->next = right;
			dummy->prev = right->prev;
			right->prev = dummy;
			right = right->next;
		}
		dummy = dummy->next;
	}
	if (left)
	{
		dummy->next = left;
		left->prev = dummy;
	}
	else
	{
		dummy->next = right;
		right->prev = dummy;
	}
	dummy = save_dummy->next;
	dummy->prev = NULL;
	free(save_dummy);
	return (dummy);
}


/**
 * merge_sort_dll - sorts a doubly linked list
 * @head: pointer to the head of the list to pointer to make effective changes
 * Return: pointer to the head of the list
 * Description: sorts a doubly linked list using the merge sort algorithm
 * Recusively in O(n log n) time
 * getting middle of the list in O(n) time using middle pointer
 */
deck_node_t *merge_sort_dll(deck_node_t **head)
{
	deck_node_t *middle;
	deck_node_t *left;
	deck_node_t *right;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (*head);
	}

	middle = get_middle(*head);
	left = *head;
	right = middle->next;
	middle->next = NULL;
	right->prev = NULL;

	left = merge_sort_dll(&left);
	right = merge_sort_dll(&right);


	*head = merge_dll(left, right);
	return (*head);
}
/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	*deck = merge_sort_dll(deck);
}
