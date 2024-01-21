#include "sort.h"
#include <stdio.h>

/**
 * swap_element - swap tow elemnt
 * @a: first elemnt
 * @b: the second element
 * Return: nothing
 */

void swap_element(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * Lomuto_partition - to choose the Lomuto partition and swap the elemnt
 * @arr: the array want to sort
 * @highe: the last element position
 * @low: the first element position
 * @size: the size of array
 * Return: the index of partion
 */

int Lomuto_partition(int arr[], int highe, int low, size_t size)
{
	int pavit = arr[highe];
	int i = low;
	int j;

	for(j = low; j < highe; j++)
	{
		printf("pivot: %d vs elemnt: %d\n", arr[highe], arr[j]);
		if (arr[j] <= pavit)
		{
			swap_element(&arr[i], &arr[j]);
			i++;
			print_array(arr, size);
		}
	}
	swap_element(&arr[i], &arr[highe]);
	return (i);
}
/**
 * quick_sort_recursive - recursion for quick sort function
 * @arr: the array want to sort
 * @low: partion index + 1 to sort the right side 
 * @hight: partition index - 1 to sort left side
 */
void quick_sort_recursive(int arr[], int low, int high, size_t size) 
{
	int Index;
	if (low < high) 
	{
		Index = Lomuto_partition(arr, high, low, size);
		quick_sort_recursive(arr, low, Index - 1, size);
		quick_sort_recursive(arr, Index + 1, high, size);
	}
}

/**
 * quick_sort - sort array in quick sort algorthim
 * @array: array want to sort
 * @size: the size of array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int highe = size - 1;

	if (array == NULL || size == 0)
		return;

	quick_sort_recursive(array, low, highe, size);

}

