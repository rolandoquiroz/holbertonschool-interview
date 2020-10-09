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
	int i, j, k, my_size;

	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
	{
		return (0);
	}

	my_size = (int) size;

	if (direction == 0)
	{
		/* slide to left */
		j = 0;
		for (i = 0; i < my_size; i++)
		{
			if (line[i] != 0)
			{
				line[j++] = line[i];
			}
		}
		while (j < my_size)
		{
			line[j++] = 0;
		}
		/* merge to left*/
		for (i = 0; i < j; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				/* shifting left next array elements */
				for (k = i + 1; k < j; k++)
				{
					line[k] = line[k + 1];
				}
				j--;
			}
		}
		/* adding zeros right */
		while (j < my_size)
		{
			line[j++] = 0;
		}
	}
	if (direction == 1)
	{
		/* slide to right */
		j = my_size - 1;
		for (i = my_size - 1; i > -1; i--)
		{
			if (line[i] != 0)
			{
				line[j--] = line[i];
			}
		}
		while (j > -1)
		{
			line[j--] = 0;
		}
		/* merge to left*/
		for (i = my_size - 1; i > j; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				/* shifting left next array elements */
				for (k = i - 1; k > j; k--)
				{
					line[k] = line[k - 1];
				}
				j++;
			}
		}
		/* adding zeros left */
		while (j > -1)
		{
			line[j--] = 0;
		}
	}

	return (1);
}
