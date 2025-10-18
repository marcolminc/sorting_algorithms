#include "sort.h"


/**
 * shell_sort - sorts an array of integers in ascending order using the
 * shell sort algorithm, using the Knuth sequence
 * @array: the array to sort
 * @size: size of the given array to sort
 *
 * Return: nothing
 * NB:
 * - prints the whole array each time the interval(gap) is decreased
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, t;
	
	if (size <= 1)
		return;
	for (gap = 1; gap < (int)size / 3; gap = 3 * gap + 1)
		;
	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			t = array[i];
			j = i;
			while (j >= gap && array[j - gap] > t)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = t;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
