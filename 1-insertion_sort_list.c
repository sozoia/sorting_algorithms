#include "sort.h"
#include <math.h>

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
	while(key != NULL)
	{
		temp = key;
		while(befor != NULL && befor->n > key->n)
		{
			if (befor->prev == NULL) 
			{
				befor->next = key->next;
				befor->prev = key;
				key->prev = NULL;
				if (temp->next != NULL)
					temp->next->prev = befor;
				key->next = befor;
			}
			if (key->next == NULL)
			{
				key->prev = befor->prev;
				befor->next = NULL;
				key->next = befor;
				if (befor->prev != NULL)
					befor->prev->next = key;
				befor->prev = key;
			}
			print_list(*list);
		}
		key = key->next;
		free(temp);
		if (befor != NULL) 
			befor = befor->next;
	}
}

