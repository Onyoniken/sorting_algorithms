#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - main function
 * @SPADE: param 1
 * @HEART: param 2
 * @CLUB: param 3
 * @DIAMOND: param 4
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - main function
 *
 * @value: Value
 * @kind: Kind
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - main function
 *
 * @card: Param 1
 * @prev: Param 2
 * @next: Param 3
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
