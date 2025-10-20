#include "sort.h"


/**
 * swap_ints - swaps values of two integer array elements and print it incase
 * of a swap
 * @array: the array
 * @size: size of array
 * @a: first(left) variable
 * @b: second(right) variable
 *
 * Return: nothing
 */
void swap_ints(int *array, size_t size, int *a, int *b)
{
	int t;

	if (*a == *b)
		return;
	t = *a;
	*a = *b;
	*b = t;
	print_array(array, size);
}


/**
 * i_left_child - determines index of left child of heap's node i
 * @i: given heap node
 *
 * Return: index of i's left child
 */
size_t i_left_child(size_t i)
{
	return (2 * i + 1);
}


/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: the given array to sort
 * @size: size of array
 *
 * Return: nothing
 * - implements the sift-down heap sort algorithm
 * - prints the array after each swap (of two elements)
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end, root, child;

	start = size / 2, end = size;
	while (end > 1)
	{
		if (start > 0)
			start--;
		else
			swap_ints(array, size, &array[--end], &array[0]);
		root = start;
		while (i_left_child(root) < end)
		{
			child = i_left_child(root);
			if (child + 1 < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
			{
				swap_ints(array, size, &array[root], &array[child]);
				root = child;
			}
			else
				break;
		}
	}
}
