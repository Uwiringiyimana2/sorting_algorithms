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
		_merge_sort(array, lower, mid);
		_merge_sort(array, mid + 1, higher);
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
	size_t n1 = mid - lower + 1;
	size_t n2 = higher - mid;

	int *left, *right;

	left = malloc(n1 * sizeof(int));
	right = malloc(n2 * sizeof(int));
	if (left == NULL)
		return;
	if (right == NULL)
		return;

	for (i = 0; i < n1; i++)
		left[i] = array[lower + i];
	for (j = 0; j < n2; j++)
		right[j] = array[mid + 1 + j];

	printf("merging...\n[left]: ");
	print_array(left, n1);

	printf("[right]: ");
	print_array(right, n2);

	i = j = 0;
	k = lower;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, higher - lower);

	free(left);
	free(right);
}
