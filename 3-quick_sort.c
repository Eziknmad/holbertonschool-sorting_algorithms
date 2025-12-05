#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 * @array: The array to partition
 * @low: Starting index of partition
 * @high: Ending index of partition
 * @size: Size of the array (for printing)
 *
 * Return: Index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts array using Quick sort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm with Lomuto partition
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Prints the array after each swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
