#include "sort.h"
#include <stdio.h>
/**
 * shell_sort - sort array in specific size in shell sort algorthim
 * @array: array wawnt to sort
 * @size: the size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap = 1;
	int temp;

	if (size < 2 || array == NULL)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
	/*	printf("gap is: %d\n", gap);*/
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && temp < array[j - gap]; j -= gap)
			{
			/*	printf("j is: %d\n",j);*/
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
}
}
