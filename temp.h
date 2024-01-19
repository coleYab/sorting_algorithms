#ifndef _TEMP_SORT
#define _TEMP_SORT

/**
 * swap - a function to swap integer values.
 *
 * @a: first number.
 * @b: second number.
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

#endif