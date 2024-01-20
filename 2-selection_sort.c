#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: given array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j;
    size_t smallest, temp;

    if (size < 2 || !array)
        return;

    for (i = 0; i < size - 1; i++)
    {
        smallest = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
        }

        if (smallest != i)
        {
            temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
            print_array(array, size);
        }
    }
}
