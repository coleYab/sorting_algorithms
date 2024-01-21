#include "sort.h"
#include "temp.h"

/**
 * selection_sort - sorts an array based on a preference.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t range, min, temp;

	if (array)
	{
		for (range = 0; range < size; range++)
		{
			temp = range;
			for (min = range; min < size; min++)
			{
				if (array[min] < array[temp])
				{
					temp = min;
				}
			}
			swap(&array[range], &array[temp]);
			print_array(array, size);
		}
	}
}
