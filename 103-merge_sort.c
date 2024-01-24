#include "sort.h"

void merge(int *array, size_t lower, size_t mid, size_t higher);
void _merge_sort(int *array, size_t lower, size_t higher);

/**
 * merge_sort - sorts an array of integers using the Merge sort
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_merge_sort(array, 0, size - 1);
}

/**
 * _merge_sort - sorts array
 * @array: array of integers
 * @lower: lower bound
 * @higher: high bound
 * Return: nothing
 */
void _merge_sort(int *array, size_t lower, size_t higher)
{
	size_t mid;

	if (lower < higher)
	{
		mid = (lower + higher) / 2;
		_merge_sort(array, lower, mid - 1);
		_merge_sort(array, mid, higher);
		merge(array, lower, mid, higher);
	}
}

/**
 * merge - merges divided array
 * @array: array of numbers
 * @lower: lower bound
 * @mid: middle
 * @higher: higher bound
 * Return: nothing
 */
void merge(int *array, size_t lower, size_t mid, size_t higher)
{
	size_t i, j, k;
	int *sorted;

	i = k = lower;
	j = mid;

	sorted = malloc((higher + 1) * sizeof(int));
	if (sorted == NULL)
	{
		free(sorted);
		return;
	}

	while (i < mid && j <= higher)
	{
		if (array[i] <= array[j])
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
		k++;
	}
	if (i >= mid)
	{
		while (j <= higher)
		{
			sorted[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i < mid )
		{
			sorted[k] = array[i];
			i++;
			k++;
		}
	}
	free(sorted);
}
