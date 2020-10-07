#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * that must be slided & merged
 * @size: size of the array of integers pointed by line
 * @direction: represents the direction to merge & slide the array
 * of integers. direction can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int my_size, i, j;


	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
	{
		return (0);
	}

	my_size = (int) size;

	if (direction == 0)
	{
		j = 0;
		for (i = 0; i < my_size; i++)
		{
			if (line[i] != 0)
			{
				line[j++] = line[i];
			}
		}
		for (i = j; i < my_size; i++)
		{
			line[i] = 0;
		}
	}

	if (direction == 1)
	{
		j = my_size - 1;
		for (i = my_size - 1; i > -1; i--)
		{
			if (line[i] != 0)
			{
				line[j--] = line[i];
			}
		}
		for (i = j; i > -1; i--)
		{
			line[i] = 0;
		}
	}

	return (1);
}
