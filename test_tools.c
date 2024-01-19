#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array printed.
 * @size: The number of elements in array.
*/
void print_array(const int *array, size_t size)
{
    size_t i = 0;

    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * print_list - prints a list of integers
 *
 * @list: the list to be printed.
*/
void print_list(const listint_t* list)
{
    int i = 0;

    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        list = list->next, i++;
    }
    printf("\n");
}