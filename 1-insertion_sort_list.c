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
			while (key->n < befor->n) 
			{
				key->prev = befor->prev;
				befor->next = key->next;
				if (befor->prev != NULL)
					befor->prev->next = key;
				if(temp->next != NULL)
					temp->next->prev = befor;
				befor->prev = key;
				key->next = befor;
				printf("ian stack");
				print_list(*list);
			}
			key = temp->next;
			befor = key->prev;
		}
	}
}

