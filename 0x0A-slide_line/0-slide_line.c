#include "slide_line.h"


/**
 * slide_line - Slides and merges an array of integers
 * @line: points to an lineay of integers containing size elements
 * that must be slided & merged
 * @size: size of the lineay of integers pointed by line
 * @direction: represents the direction to merge & slide the lineay
 * of integers. direction can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int my_size, i, j, k, count;

	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
	{
		return (0);
	}

	my_size = (int) size;

	j = 0;
	for (i = 0; i < my_size; i++)
	{
		if (line[i] != 0)
		{
			line[j++] = line[i];
		}
	}
	count = j;
	for (i = j; i < my_size; i++)
	{
		line[i] = 0;
	}

	for (i = 0; i < count; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] = 2 * line[i];
			for (k = i + 1; k < count; k++)
			{
				line[k] = line[k + 1];
			}
			count--;
			j--;
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
		count = j;
		for (i = j; i > -1; i--)
		{
			line[i] = 0;
		}
	}
	return (1);
}
