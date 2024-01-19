#include "sort.h"

/**
 * swap - swaps numbers in array
 * @xp: number
 * @yp: number
 * Return: Nothing
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
