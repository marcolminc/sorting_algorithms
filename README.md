# 0x1B.C - Sorting algorithms & big O

#### Requirements

* Allowed editors: vi, vim, emacs
* All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
* Code should use the Betty style
* Not allowed to use global variables
* No more than 5 functions per file
* Unless specified otherwise, not allowed to use the standard library. Use of functions like printf, puts, ... is
  totally forbidden
* Prototypes of all functions should be included in the header file called `sort.h`
* All header files should be include guarded
* A list/array does not need to be sorted if its size is less than 2
* given functions for this project:
    ```C
    #include <stdlib.h>
    #include <stdio.h>
    
    /**
     * print_array - Prints an array of integers
     *
     * @array: The array to be printed
     * @size: Number of elements in @array
     */
    void print_array(const int *array, size_t size)
    {
        size_t i;
    
        i = 0;
        while (array && i < size)
        {
            if (i > 0)
                printf(", ");
            printf("%d", array[i]);
            ++i;
        }
        printf("\n");
    }
    ```
    ```C  
    #include <stdio.h>
    #include "sort.h"
    
    /**
     * print_list - Prints a list of integers
     *
     * @list: The list to be printed
     */
    void print_list(const listint_t *list)
    {
        int i;
    
        i = 0;
        while (list)
        {
            if (i > 0)
                printf(", ");
            printf("%d", list->n);
            ++i;
            list = list->next;
        }
        printf("\n");
    }
    ```
* provided data structure for doubly linked list:
    ```C
    /**
     * struct listint_s - Doubly linked list node
     *
     * @n: Integer stored in the node
     * @prev: Pointer to the previous element of the list
     * @next: Pointer to the next element of the list
     */
    typedef struct listint_s
    {
        const int n;
        struct listint_s *prev;
        struct listint_s *next;
    } listint_t;
    ```

#### Tasks

1. 0.Bubble sort: write a function that sorts an array of integers in ascending order using the *Bubble sort algorithm*
2. 1.Insertion sort list:
3. 2.Selection sort: write a function that sorts an array of integers in ascending order using the *Selection sort* algorithm
*
2. 1.Insertion sort list: write a function that sorts a doubly linked list of integers in ascending order using the *Insertion sort* algorithm
3. 2.Selection sort: write a function that sorts an array of integers in ascending order using the *Selection sort* algorithm
4. 3.Quick sort: write a function that sorts an array of integers in ascending order using the *Quick sort* algorithm
5. 4.Shell sort -Knuth Sequence: write a function that sorts an array of integers in ascending order using the *Knuth sequence algorithm*
6. 5.Cocktail sort:
7. 6.Counting sort: Write a function that sorts an array of integers in 
ascending order using the Counting sort algorithm
8. 7.
9. 8.Heap sort: write a function that sorts an array of integers in ascending order using the Heap sort algorithm

