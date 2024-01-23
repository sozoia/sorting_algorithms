#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swap tow node in duobly linked list
 * @key: the first node
 * @befor: the second node
 * Return: nothing
 */

void swap_node(listint_t *key, listint_t *befor)
{
	if (befor->prev != NULL)
		befor->prev->next = key;
	if (key->next != NULL)
		key->next->prev = befor;

	befor->next = key->next;
	key->prev = befor->prev;
	key->next = befor;
	befor->prev = key;
}

/**
 * cocktail_sort_list - sort doubly linked list in cocktail_sort algorthim
 * @list: the list want to sort
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *befor;
	listint_t *temp;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;
	key = (*list)->next;
	befor = *list;
	while (swapped == 0)
	{
		swapped = 1;

		while (key != NULL)
		{
			if (key->n < befor->n)
			{
				swap_node(key, befor);
				if (key->prev == NULL)
					*list = key;
				temp = key;
				key = befor;
				befor = temp;

				swapped = 0;
				print_list(*list);
			}

			key = key->next;
			befor = befor->next;

		}
		if (swapped != 0)
			break;

		key = befor->prev;
		befor = befor->prev->prev;

		swapped = 1;
		while (befor != NULL)
		{
			if (befor->n > key->n)
			{
				swap_node(key, befor);
				if (key->prev == NULL)
					*list = key;
				temp = key;
				key = befor;
				befor = temp;

				swapped = 0;
				print_list(*list);
			}
			befor = befor->prev;
			key = key->prev;

		}
		befor = key;
		key = key->next;
	}
}

