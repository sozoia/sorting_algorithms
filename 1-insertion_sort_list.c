#include "sort.h"

/**
 * insertion_sort_list - srting list in insertion sort algorthim
 * @list: the head of duobly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key = *list;
	listint_t *befor = *list;
	listint_t *temp = malloc(sizeof(listint_t));

	key = key->next;
	while(key != NULL && temp != NULL)
	{
		temp = key;
		while(befor->n > temp->n && befor != NULL)
		{
			key = befor;
			befor = befor->prev;
			print_list(*list);
		}
		key = temp;
		key = key->next;
		befor = befor->next;
	}
}

