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
			if (temp == range)
				continue;
			swap(&array[range], &array[temp]);
			print_array(array, size);
		}
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
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