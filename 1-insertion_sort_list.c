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
	if (list != NULL)
	{
		while(key != NULL)
		{
			temp = key;
			while (befor != NULL && key->n < befor->n) 
			{
				if (befor->prev != NULL)
					befor->prev->next = key;
				if(temp->next != NULL)
					temp->next->prev = befor;
				befor->next = key->next;
				key->prev = befor->prev;
				key->next = befor;
				befor->prev = key;
				
				befor = key->prev;
				if (key->prev == NULL) 
					*list = key;
				print_list(*list);
			}
			key = temp->next;
			if(key != NULL)
				befor = key->prev;
		}
	}
}

