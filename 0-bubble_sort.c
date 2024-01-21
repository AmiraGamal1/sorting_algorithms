#include "sort.h"
/**
  * bubble_sort - bubble sort
  *
  * @array: array to sort it
  *
  * @size: size of the array
  *
  * Return: nothings
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= size - 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
