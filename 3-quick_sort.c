#include "sort.h"

/**
  * partion - partion according to the pivot (use Lomuto)
  *
  * @array: array
  *
  * @low: low index
  *
  * @high: high index
  *
  * @size: size of the array
  *
  * Return: index of the pivot
  */
int partion(int *array, size_t size, int low, int high)
{
	int pivot, tmp, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	i = i + 1;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (i != high)
		print_array(array, size);

	return (i);
}
/**
  * quick - recursive quick sort
  *
  * @array: the array
  *
  * @low: low index
  *
  * @high: high index
  *
  * @size: size of the array
  *
  * return: nothigs
  */
void quick(int *array, size_t size, int low, int high)
{
	int p;

	if (high < low || low < 0)
		return;
	p = partion(array, size, low, high);
	quick(array, size, low, p - 1);
	quick(array, size, p + 1, high);
}
/**
  * quick_sort - quick sort
  *
  * @array: array of int
  *
  * @size: size of the array
  *
  * Return: nothighs
  */
void quick_sort(int *array, size_t size)
{
	quick(array, size, 0, size - 1);
}
