#include "sort.h"

/**
 * selection_sort - sort array using selection sort algo
 * @array: given array
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
    size_t i, j;
    int greater, main;

        if (size < 1 || !array)
                return;

    for(i = 0; i < size; i++)
    {
        main = array[i];

        for(j = i; j < size; j++)
        {
            if (array[j] < main)
            {
                greater = main;
                array[i] = array[j];    /*i is current index*/
                array[j] = greater;     /*j is the moving curser*/
                break;
            }
        }
        if (array[i] != main)
        {
            print_array(array, size);
            i = -1;
        }
    }
}
