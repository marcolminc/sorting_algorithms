#include "sort.h"


/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: the given array to sort
 * @size: size of the input array
 *
 * Return: nothing
 * - the array is printed after each time a swap occurs
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, j_min;
	int t;

	for (i = 0; i < size - 1; i++)
	{
		j_min = i;
		for (j = i; j < size; j++)
			if (array[j] < array[j_min])
				j_min = j;
		if (j_min != i)
		{
			t = array[j_min];
			array[j_min] = array[i];
			array[i] = t;
			print_array(array, size);
		}
	}
}
