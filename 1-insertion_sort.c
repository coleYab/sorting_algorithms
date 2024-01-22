#include "sort.h"

/**
 * insertion_sort_list - this is the function to implement an insertion sort.
 *
 * @list: is the list of integer.
 */
void insertion_sort_list(listint_t **list)
{
	//go back to the end of the list
	swap_dll(*list, (*list)->next);
	print_list(*list);	
}


/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}

void swap_dll(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp1, *temp2;

	if (!head || !*head || !node1 || !node2)
		return;
	if (*head == node1)
		*head = node2;
	temp1 = node1->next;
	temp2 = node1->prev;
	if (temp1)
		temp1->prev = node2;
	if (temp2)
		temp2->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	if (node2->prev)
		node2->prev->next = node1;
	node1->next = node2->next;
	node1->prev = node2->prev;
	node2->prev = temp2;
	node2->next = temp1;
}

