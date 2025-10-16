#include "sort.h"


/**
 * swap_array - swaps values of two indexes of an integer array
 * @array: the array
 * @a: first variable
 * @b: second variable
 *
 * Return: nothing
 * NB: prints the (whole) array after every swap
 */
void swap_array(int *array, const int a, const int b, size_t size)
{
	int temp;

	if (a == b)
		return;
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}


/**
 * partition - partitions an array of integers (subarray) using Lomuto scheme
 * @array: the (sub) array to partition
 * @lo: lower bound
 * @hi: higher bound
 *
 * Return: final index for current pivot value
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int p, i, b;

	p = array[hi];
	b = lo - 1;
	for (i = lo; i < hi; i++)
	{
		if (array[i] < p)
		{
			swap_array(array, ++b, i, size);
		}
	}
	swap_array(array, ++b, hi, size);
	return (b);
}


/**
 * quick_sort_helper - recursive helper for quick sorting with lomuto partition scheme
 * @array: the (sub)array to sort
 * lo: lower bound of the (sub)array
 * hi: higher bound of the (sub)array
 * size: size of the whole array - for printing in case of swapping
 *
 * Return: nothing
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int pi;

	if (lo < hi)
	{
		pi = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pi - 1, size);
		quick_sort_helper(array, pi + 1, hi, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm - with Lomuto partition scheme
 * @array: the array to sort
 * @size: size of the array given to sort
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, (int)size - 1, size);
}
