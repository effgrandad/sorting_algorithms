#include "sort.h"

/**
 * swap_nodes - switch two nodes in a listint_t doubly-linked list
 * @f: pionter pointing to the head of the doubly-linked list
 * @m1: pointer pointing to the first node to swap
 * @m2: second node to be swapped
 */
void swap_nodes(listint_t **f, listint_t **m1, listint_t *m2)
{
	(*m1)->next = m2->next;
	if (m2->next != NULL)
		m2->next->prev = *m1;
	m2->prev = (*m1)->prev;
	m2->next = *m1;
	if ((*m1)->prev != NULL)
		(*m1)->prev->next = m2;
	else
		*f = m2;
	(*m1)->prev = m2;
	*m1 = m2->prev;
}

/**
 * insertion_sort_list - Sorting a doubly linked list of integers with
 * the insertion sort algorithm
 * @list: pointer pointing to the head doubly-linked list.
 * Description: after each swap print the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;
	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
