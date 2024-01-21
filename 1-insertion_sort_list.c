#include "sort.h"


// void swap_list(listint_t *temp1, listint_t *temp2)
// {
//     listint_t *a = temp1->prev, *b = temp1->next;

//     if (temp1->prev)
//         temp1->prev->next = temp2;
//     if (temp1->next)
//         temp1->next->prev = temp2;
//     temp1->next = temp2->next;
//     temp1->prev = temp2->prev;
//     if (temp2->next)
//         temp2->next->prev = temp1;
//     if (temp2->prev)
//         temp2->prev->next = temp1;
//     temp2->prev = a;
//     temp2->next = b;
// }

// void insertion_sort_list(listint_t **list)
// {
//     listint_t *val, *head, *temp;

//     if (list && *list && (*list)->next)
//     {
//         head = *list;
//         while (head)
//         {
//             temp = head;
//             for (val = temp->prev; val->prev && val->n > temp->n; val = val->prev)
//             {
//                 swap_list(temp, val);
//                 print_list(*list);
//             }
//             head = head->next;
//         }
//     }


// }

// /*insertion sort using arrays*/
// void insertion_sort_arr(int *arr, int size)
// {
//     int val;

//     for (int i = 0; i < size; i++)
//     {
//         int temp = arr[i];
//         for (val = i; val > 0 && temp < arr[val - 1]; val--)
//         {
//             arr[val] = arr[val - 1];
//             arr[val - 1] = temp;
//             print_array(arr, size);
//         }
//     }
// }


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

void swap_list(listint_t *temp1, listint_t *temp2)
{
    listint_t *a = temp1->prev, *b = temp1->next;

    if (temp1->prev)
        temp1->prev->next = temp2;
    if (temp1->next)
        temp1->next->prev = temp2;
    temp1->next = temp2->next;
    temp1->prev = temp2->prev;
    if (temp2->next)
        temp2->next->prev = temp1;
    if (temp2->prev)
        temp2->prev->next = temp1;
    temp2->prev = a;
    temp2->next = b;

    /* Update head pointer if needed */
    if (a == NULL)
        *(&temp1) = temp2;
}

void insertion_sort_list(listint_t **list)
{
    listint_t *val, *head, *temp;

    if (list && *list && (*list)->next)
    {
        head = *list;
        while (head)
        {
            temp = head;
            for (val = temp->prev; val && val->n > temp->n; val = val->prev)
            {
                swap_list(temp, val);
                print_list(*list);
            }
            head = head->next;
        }
    }
}


