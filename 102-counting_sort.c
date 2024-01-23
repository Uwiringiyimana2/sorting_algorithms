#include "sort.h"

int key(int *array, size_t size);

/**
 * counting_sort - sorts an array of integers using the Counting sort
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
		return;

	max = key(array, size);
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i <= (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		++count[array[i]];

	for (i = 0; i <= (max + 1); i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted[i];
	}
	free(count);
	free(sorted);
}
/**
 * key - finds highest number
 * @array: array of integers
 * @size: size of array
 * Return: highest number
 */
int key(int *array, size_t size)
{
	size_t i, high_idx = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > array[high_idx])
			high_idx = i;
	}
	return (array[high_idx]);
}
