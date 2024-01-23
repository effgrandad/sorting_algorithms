#include "sort.h"

/**
 * swap_ints - swap two values within an array
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
 * bubble_sort - array of integers is sorted in ascending order
 * @array: array of integers to sort
 * @size: size of array
 * Description: after each swap print array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, lenn = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (a = 0; a < lenn - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_ints(array + a, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		lenn--;
	}
}
