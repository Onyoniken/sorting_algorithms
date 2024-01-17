#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - main function
 * @s1: param 1
 * @s2: param 2
 *
 * Return: Positive/negative
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - main function
 * @card: pointer
 *
 * Return: card value
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - main function
 * @deck: param 1
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *i, *n, *t;

	for (i = (*deck)->next; i != NULL; i = t)
	{
		t = i->next;
		n = i->prev;
		while (n != NULL && n->card->kind > i->card->kind)
		{
			n->next = i->next;
			if (i->next != NULL)
				i->next->prev = n;
			i->prev = n->prev;
			i->next = n;
			if (n->prev != NULL)
				n->prev->next = i;
			else
				*deck = i;
			n->prev = i;
			n = i->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - main function
 * @deck: param 1
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *i, *n, *t;

	for (i = (*deck)->next; i != NULL; i = t)
	{
		t = i->next;
		n = i->prev;
		while (n != NULL &&
		       n->card->kind == i->card->kind &&
		       get_value(n) > get_value(i))
		{
			n->next = i->next;
			if (i->next != NULL)
				i->next->prev = n;
			i->prev = n->prev;
			i->next = n;
			if (n->prev != NULL)
				n->prev->next = i;
			else
				*deck = i;
			n->prev = i;
			n = i->prev;
		}
	}
}

/**
 * sort_deck - main function
 * @deck: param 1
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
