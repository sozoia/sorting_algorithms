#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  * swap_node - swap two nodes in doubly linked list
 *   * @key: the first node
 *    * @befor: the second node
 *     * Return: nothing
 *      */

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
 *  * insertion_sort_list - sorting list using insertion sort algorithm
 *   * @list: the head of doubly linked list
 *    * Return: nothing
 *     */
void insertion_sort_list(listint_t **list)
{
		listint_t *key = *list;
			listint_t *befor = *list;

				if (list == NULL || *list == NULL || key->next == NULL)
							return;

					key = key->next;
						while (key != NULL)
								{
											while (befor != NULL && key->n < befor->n)
														{
																		swap_node(key, befor);
																		    if (key->prev != NULL)
																				    key->prev->next = key;

																					befor = befor->prev;
																								if (key->prev == NULL)
																										*list = key;
																											print_list(*list);
																													}
													key = key->next;
														}
}

