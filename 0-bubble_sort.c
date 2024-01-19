#include "sort.h"
#include "temp.h"


/**
 * bubble_sort - the laziest and the most easiest
 * sorting alghoritms in human life.
 *
 * @array: is the array given.
 * @size: is the size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	int curr = 0, next = 1;
	int swapped = 1;

	while (array && swapped && next < size)
	{
		swapped = 0;
		for ( ; next < size; next++, curr++)
		{
			if (array[curr] > array[next])
			{
				swap(&array[curr], &array[next]);
				print_array(array, size);
				swapped += 1;
			}
		}
		curr = 0, next = 1;
	}
}
