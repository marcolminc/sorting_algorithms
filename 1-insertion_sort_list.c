#include "sort.h"


/**
 * swap - swaps listint_t nodes
 * @l: the left node
 * @r: the right node
 * @head: pointer to head pointer of the list
 *
 * Return: nothing
 *
 * prints the (whole) list after every swap
 */
void swap(listint_t **l, listint_t **r, listint_t **head)
{
	listint_t *lp, *rn;

	if (!l || !*l || !r || !*r || !head || !*head)
		return;
	lp = (*l)->prev;
	rn = (*r)->next;

	if (lp)
		lp->next = *r;
	else
		*head = *r;

	(*r)->prev = lp;
	(*r)->next = *l;

	(*l)->prev = *r;
	(*l)->next = rn;

	if (rn)
		rn->prev = *l;

	print_list(*head);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: the doubly linked list
 *
 * Return: nothing
 * - Swaps the nodes themselves, rather than modifying the integer n of a node
 * - prints the list after every swap two elements
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *curr, *nxt;

	if (!list || !*list || !(*list)->next)
		return;
	curr = (*list)->next;
	while (curr)
	{
		nxt = curr->next;
		prev = curr->prev;
		while (prev && curr->n < prev->n)
		{
			swap(&prev, &curr, list);
			prev = curr->prev;
		}
		curr = nxt;
	}
}
