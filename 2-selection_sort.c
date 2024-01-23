#include "sort.h"

/**
 * swap_ints - swap two integer values in an array
 * @f: first value to swap
 * @h: second value to swap
 */
void swap_ints(int *f, int *h)
{
	int temp;

	temp = *f;
	*f = *h;
	*h = temp;

}

/**
 * selection_sort - selection sort technique is used to arrange an
 * array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Description: after each swap, print array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, j;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (j = a + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + a) != min)
		{
			swap_ints(array + a, min);
			print_array(array, size);
		}
	}
}
