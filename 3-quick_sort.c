#include "sort.h"
 
void swap_ints(int *f, int *h);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

/**
 * swap_ints - swap two integers values in an array
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
 * lomuto_partition - arrange a portion of an array of integers using
 * the lomuto partition scheme(last element as pivot).
 * @array: array of integers
 * @size: size of the array
 * @left: start of index's subset to order
 * @right: the end of index's subset to order
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - implementing the quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: the start of index's partition array to order
 * @right: the end of index's partition array to order
 * Description: utilizes the Lomuto partition algorithm
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - quicksort technique is used to sort an array of
 * integers in ascending order
 * @array: an array of integers
 * @size: size of the array
 * Description: utlize the Lomuto partition scheme. after each swap
 * display array ofveach elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}