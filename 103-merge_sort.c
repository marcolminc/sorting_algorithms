#include "sort.h"
#include <stdlib.h>

/**
 * merge - merges two sorted arrays into one larger array
 * @array: the original array being sorted
 * @left: the left sub-array after division
 * @l_len: size of left
 * @right: the right sub-array after division
 * @r_len: size of right
 */
void merge(int *array, int *left, size_t l_len, int *right, size_t r_len)
{
    size_t i, j, k;

    i = j = k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, l_len);
    printf("\n[right]: ");
    print_array(right, r_len);
    printf("\n");

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
    printf("\n");
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * merge sort algorithm (top-down)
 * @array: the array given to sort
 * @size: length (size) of array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid, i;
    int *buffer;

    if (size <= 1)
        return;

    mid = size / 2;
    buffer = malloc(size * sizeof(int));
    if (!buffer)
        return; /* Handle allocation failure */

    for (i = 0; i < mid; i++)
        buffer[i] = array[i];
    for (i = mid; i < size; i++)
        buffer[i] = array[i];

    merge_sort(buffer, mid);
    merge_sort(buffer + mid, size - mid);

    merge(array, buffer, mid, buffer + mid, size - mid);
    free(buffer);
}

