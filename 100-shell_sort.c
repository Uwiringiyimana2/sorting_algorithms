#include "sort.h"

void swap_shell(int *xp, int *yp);
void shell_sort(int *array, size_t size);

/**
 * shell_sort - sorts array of integers using the shell sort
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j;
	int i;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] < array[i])
					swap_shell(&array[i + gap], &array[i]);
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_shell - swap numbers
 * @xp: number
 * @yp: number
 * Return: Nothing
 */
void swap_shell(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
