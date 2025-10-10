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
	int temp;

	for (i = 0; i < size; i++)
	{
		s = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				s = 1;
			}
		}
		if (!s)
			break;
	}
}
