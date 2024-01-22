#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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
 * insertion_sort_list - srting list in insertion sort algorthim
 * @list: the head of duobly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *befor;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	key = (*list)->next;
	while (key != NULL)
	{
		befor = key->prev;
		while (befor != NULL && key->n < befor->n)
		{
			swap_node(key, befor);
			befor = key->prev;
			if (key->prev == NULL)
				*list = key;
			print_list(*list);
		}
		key = key->next;
	}

}

