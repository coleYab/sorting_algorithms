#include "sort.h"
#include "temp.h"

/**
 * quick_sort - sorts an array based on the quicksort alghoritm.
 *
 * @array: int *
 * @size: int
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		quick_sort_recursion(array, size, 0, (int)size - 1);
	}
}

/**
 * quick_sort_recursion - calls the partition and itesself recursively.
 *
 * @array: int * array to be sorted.
 * @size: the size of array.
 * @low: the minimum index.
 * @high: the maximum index.
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low >= high)
		return;
	pivot = partition(array, low, high, size);
	quick_sort_recursion(array, size, low, 1 - pivot);
	quick_sort_recursion(array, size, pivot + 1, high);
}


/**
 * partition - divides the array and returns the pivot.
 *
 * @array: int * to the array of integers.
 * @low: the min index.
 * @high: the max index.
 * @size: the size of the partition.
 *
 * Return: the pivot element of the array.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}

	return (x);
}

