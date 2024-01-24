#include "sort.h"

/**
 * swap_ints - swap two integer values of an array
 * @f: first integer value to swap
 * @h: second integer value to swap
 */
void swap_ints(int *f, int *h)
{
	int temp;

	temp = *f;
	*f = *h;
	*h = temp;
}

/**
 * shell_sort - use the shell sort method to arrange an array
 * of numbers in ascending order
 * @array: array of integers
 * @size: size of array
 * Description: utilize the order of Knuth interval
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, k, s;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 2);)
		gap = gap * 3 + 1;

	for (gap = gap * 3 + 1; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			s = k;
			while (s >= gap && array[s - gap] > array[s])
			{
				swap_ints(array + s, array + (s - gap));

				s -= gap;
			}
		}
		print_array(array, size);
	}
}
