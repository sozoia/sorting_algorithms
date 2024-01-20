#include "sort.h"
<<<<<<< HEAD

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
=======
#include <stdlib.h>

/**
 *  * insertion_sort_list - sort a doubly linked list using insertion sort
 *   * @list: the head of the doubly linked list
 *    */
void insertion_sort_list(listint_t **list)
{
		listint_t *key, *before, *temp;

			if (list == NULL || *list == NULL || (*list)->next == NULL)
						return;

				key = (*list)->next;

					while (key != NULL)
							{
										temp = key;
												before = key->prev;

														while (before != NULL && temp->n < before->n)
																	{
																					if (before->prev != NULL)
																										before->prev->next = temp;

																								if (temp->next != NULL)
																													temp->next->prev = before;

																											before->next = temp->next;
																														temp->prev = before->prev;
																																	temp->next = before;
																																				before->prev = temp;

																																							before = temp->prev;

																																										if (temp->prev == NULL)
																																															*list = temp;

																																													print_list(*list);
																																															}

																key = temp->next;
																	}
}

>>>>>>> 5f06d76 (update)
