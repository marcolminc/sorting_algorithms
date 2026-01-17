#include "sort.h"
#include <stdlib.h>

/**
 * merge - merges two sorted subarrays into a larger sorted array
 * @array: the original array being sorted
 * @buffer: temporary buffer for merging
 * @left: start index of the left subarray
 * @mid: end index of the left subarray (start of right subarray)
 * @right: end index of the right subarray
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("\n[right]: ");
	print_array(array + mid, right - mid);
	printf("\n");

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
	printf("\n");
}

/**
 * merge_sort_helper - recursive helper for merge sort
 * @array: the array to sort
 * @buffer: temporary buffer for merging
 * @left: start index of the subarray
 * @right: end index of the subarray
 */
void merge_sort_helper(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;
	merge_sort_helper(array, buffer, left, mid);
	merge_sort_helper(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the top-down merge sort algorithm
 * @array: the array to sort
 * @size: length (size) of array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (size <= 1)
		return;

	buffer = malloc(size * sizeof(int));
	if (!buffer)
		return;

	merge_sort_helper(array, buffer, 0, size);
	free(buffer);
}
