#include "sort.h"

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

int Lomuto_partition(int arr[], int highe, int low)
{
	int pavit = arr[highe];
	int i = low - 1;
	int j = low;

	while(j <= highe - 1)
	{
		if (arr[j] <= pavit)
		{
			i++;
			swap_element(&arr[i], &arr[j]);
			print_array(arr, low);
		}
		j++;
	}
	swap_element(&arr[i + 1], &arr[highe]);
	return (i + 1);
}
/**
 * quick_sort_recursive - recursion for quick sort function
 * @arr: the array want to sort
 * @low: partion index + 1 to sort the right side 
 * @hight: partition index - 1 to sort left side
 */
void quick_sort_recursive(int arr[], int low, int high) 
{
	int Index;
	if (low < high) 
	{
		Index = Lomuto_partition(arr, high, low);
		quick_sort_recursive(arr, Index - 1, low);
		quick_sort_recursive(arr, high, Index + 1);
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

	quick_sort_recursive(array, low, highe);

}

