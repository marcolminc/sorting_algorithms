#include "sort.h"

/**
 * max_element - determines the maximum integer element(value) in an array
 * @array: the given array
 * @size: size of the given array
 *
 * Return: (int) the maximum element(value) of the given array
 */
int max_element(const int *array, size_t size)
{
	int max;

	if (!size)
		return (-1);
	max = array[0];
	while (--size)
		if (array[size] > max)
			max = array[size];
	return (max);
}


/**
 * counting_sort_lsd - sorts an array of integers using the Counting sort
 * algorithm and the radix from lsd significant digit up (to the left)
 * @array: the array given to sort
 * @size: size of array
 * @exp: determinant of significant digit position
 * @max: largest integer element in the input array
 *
 * Return: nothing
 */
void counting_sort_lsd(int *array, size_t size, int exp, int max)
{
	int *res, count[10] = {0};
	size_t i;

	res = malloc(size * sizeof(int));
	if (!res)
		exit(98);
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i < (size_t)max; i--)
	{
		res[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = res[i];
	free(res);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: the array given to sort
 * @size: size of array
 *
 * Return: nothing
 * - implements the LSD radix sort algorithm
 * - array will contain only numbers >= 0
 * - may use malloc and free
 * - prints the array each time the significant digit is increased
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;
	max = max_element(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_lsd(array, size, exp, max);
		print_array(array, size);
	}
}
