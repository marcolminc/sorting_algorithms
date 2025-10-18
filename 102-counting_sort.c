#include "sort.h"


/**
 * init_array - allocates memory for an integer array (0 initialized)
 * @max: determinant of the size of an array - expected max index
 *
 * Return: the initialized array, NULL otherwise
 */
int *init_array(size_t max)
{
	int *res, i;

	res = malloc((max + 1) * sizeof(int));
	if (res)
		for (i = 0; i < max + 1; i++)
			res[i] = 0;
	return ((res) ? res : NULL);
}


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
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: the array of integers to sort
 * @size: size of the input array
 *
 * Return: nothing
 * Description:
 * - the array will contain only numbers >= 0
 * - allowed to use malloc and free
 * - prints the counting array once it is set
 * - the counting array is of size k + 1 where k is the largest number in array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *res, i, j, max;

	if (size < 2)
		return;
	max = max_element(array, size);
	if (max == -1)
		exit(98);
	count = init_array(max);

	if (!count)
		exit(98);
	res = init_array(size);
	if (!res)
	{
		free(count);
		exit(98);
	}
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = (int)size - 1; i >= 0; i--)
	{
		j = array[i];
		count[j]--;
		res[count[j]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = res[i];
	free(res);
	free(count);
}
