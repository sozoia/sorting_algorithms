#include "sort.h"
#include <stdio.h>


/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: given array we will sort
 * @size: size of that array
 *
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 1 || !array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{	/*swap values of elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
