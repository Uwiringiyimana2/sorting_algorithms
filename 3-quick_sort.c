#include "sort.h"

void _quick_sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void quick_sort(int *array, size_t size);

/**
 * quick_sort - sorts array of integers using the quick sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - implement the quicksort algorithm through recursion
 * @array: An array of integers
 * @low: the starting index of partition
 * @high: the ending index
 * @size: size of array
 * Return: nothing
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (high - low > 0)
	{
		pi = partition(array, low, high, size);
		_quick_sort(array, low, pi - 1, size);
		_quick_sort(array, pi + 1, high, size);
	}
}

/**
 * partition - lomuto partition scheme
 * @array: array of intagers
 * @low: starting index of sub array to order
 * @high: the ending index of subarray to order
 * @size: size of array
 * Return: nothing
 */
int partition(int *array, int low, int high, size_t size)
{
	int *pivot, above, below;

	pivot = array + high;

	for (above = below = low; below <= high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * swap - swapping integers of array
 * @a: first integer
 * @b: second integer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
