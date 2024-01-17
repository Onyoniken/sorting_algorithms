#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - main function
 * @list: pointer to list
 * @tail: pointer to tail
 * @shaker: shaker to pointer
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - main functlion
 * @list: pointer to list
 * @tail: pointer to tail
 * @shaker: pointer of swapping node
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - main function
 * @list: A pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *s;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (s = *list; s != t; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swap_node_ahead(list, &t, &s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (s = s->prev; s != *list;
				s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swap_node_behind(list, &t, &s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
