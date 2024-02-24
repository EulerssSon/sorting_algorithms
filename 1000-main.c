#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * print_deck - Prints the deck
 *
 * @deck: Deck to print
 */
void print_deck(const deck_node_t *deck)
{
	size_t i;
	char kinds[4] = {
		'S', 'H', 'C', 'D'
	};

	i = 0;
	while (deck)
	{
		if (i)
			printf(", ");
		printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
		if (i == 12)
			printf("\n");
		i = (i + 1) % 13;
		deck = deck->next;
	}
}

/**
 * init_deck - Initialize the deck ll
 *
 * @cards: Array of cards
 *
 * Return: List of cards
 */
deck_node_t *init_deck(const card_t cards[52])
{
	deck_node_t *deck;
	deck_node_t *node;
	size_t i;

	i = 52;
	deck = NULL;
	while (i--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		node->card = &cards[i];
		node->next = deck;
		node->prev = NULL;
		if (deck)
			deck->prev = node;
		deck = node;
	}
	return (deck);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	card_t cards[52] = {
		{"7", SPADE}, {"Queen", DIAMOND}, {"6", HEART}, {"Ace", DIAMOND}, {"8", SPADE}, {"2", DIAMOND}, {"Jack", SPADE}, {"6", CLUB}, {"7", CLUB}, {"Ace", HEART}, {"5", SPADE}, {"5", DIAMOND}, {"7", DIAMOND}, {"Ace", SPADE}, {"10", HEART}, {"Queen", HEART}, {"7", HEART}, {"King", DIAMOND}, {"5", CLUB}, {"2", SPADE}, {"King", CLUB}, {"9", SPADE}, {"2", CLUB}, {"Jack", HEART}, {"Ace", CLUB}, {"4", CLUB}, {"9", CLUB}, {"9", DIAMOND}, {"3", CLUB}, {"10", SPADE}, {"8", DIAMOND}, {"6", SPADE}, {"4", DIAMOND}, {"3", SPADE}, {"King", HEART}, {"2", HEART}, {"Queen", SPADE}, {"King", SPADE}, {"10", DIAMOND}, {"Jack", CLUB}, {"Queen", CLUB}, {"4", SPADE}, {"4", HEART}, {"6", DIAMOND}, {"3", DIAMOND}, {"8", HEART}, {"5", HEART}, {"Jack", DIAMOND}, {"3", HEART}, {"10", CLUB}, {"8", CLUB}, {"9", HEART}
	};
	deck_node_t *deck;

	deck = init_deck(cards);
	print_deck(deck);
	printf("\n");
	sort_deck(&deck);
	printf("\n");
	print_deck(deck);
	return (0);
}
