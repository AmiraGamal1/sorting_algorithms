#include "sort.h"

/**
  * swap - swap two adjacent node in a double linked list
  *
  * @left: left node
  *
  * @right: right node
  *
  * Return: nothings
  */
listint_t *swap(listint_t *left, listint_t *right)
{
	left->next = right->next;
	if (left->next)
		left->next->prev = left;
	right->prev = left->prev;
	if (right->prev)
		right->prev->next = right;
	right->next = left;
	left->prev = right;

	return (right);
}
/**
  * len - list length
  *
  * @list: list head
  *
  * Return: lenght of the list
  */
int len(listint_t **list)
{
	int l = 0;
	listint_t *tmp = *list;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		l++;
	}
	free(tmp);
	return (l);
}

/**
  * insertion_sort_list - insertion sort
  *
  * @list: head of the double linked list
  *
  * Return: nothings
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *left;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	for (tmp = *list; tmp != NULL; tmp = tmp->next)
	{
		left = tmp->prev;
		while (left != NULL)
		{
			if (left->n > left->next->n)
			{
				left = swap(left, left->next);
				if (left->prev  == NULL)
					*list = left;
				print_list(*list);
			}
			left = left->prev;
		}
	}
}
