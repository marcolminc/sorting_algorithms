#include "sort.h"


/**
 * merge - merges two sorted arrays into one larger array
 * @array: the original array being sorted
 * @left: the left sub-array after division
 * @l_len: size of left
 * @right: the right sub-array after division
 * @r_len: size of right
 *
 * Return: nothing
 */
void merge(int *array, int *left, size_t l_len, int *right, size_t r_len)
{
	size_t i, j, k;

	i = j = k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_len);
	printf("[right]: ");
	print_array(right, r_len);

	while (i < l_len && j < r_len)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < l_len)
		array[k++] = left[i++];
	while (j < r_len)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, l_len + r_len);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * merge sort algorithm (top-down)
 * @array: the array given to sort
 * @size: length (size) of array
 *
 * Return: nothing
 * - when an array is divided, the size of left sub-array should always be
 * <= the size of right sub-array
 * - left sub-array is sorted before the right sub-array
 * - allowed to use malloc and free only once (only one call)
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int left[size / 2], right[size - (size / 2)];
	if (size <= 1)
		return;
	mid = size / 2;
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);
}
