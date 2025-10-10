#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: the array given to sort
 * @size: size of the given array
 *
 * Return: nothing
 * NB: required to print the array after each swap of two elements
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, s;

	for (j = 0; j < size; j++)
	{
		s = 0;
		for (i = 0; i < size - j - 1; i++)
			if (array[i + 1] < array[i])
			{
				array[i + 1] = array[i + 1] + array[i];
				array[i] = array[i + 1] - array[i];
				array[i + 1] = array[i + 1] - array[i];
				s++;
			}
		if (!s)
			break;
		print_array(array, size);
	}
}
