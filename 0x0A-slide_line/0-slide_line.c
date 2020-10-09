#include "slide_line.h"

/**
 * slide_line_left - Slides and merges an array of integers
 * @line: points to an lineay of integers containing size elements
 * that must be slided & merged
 * @my_size: size of the lineay of integers pointed by line
 * of integers. direction can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: nothing
 */
void slide_line_left(int *line, int my_size)
{
	int i, j, k;
	/* slide to left */
	j = 0;
	i = 0;
	while (i < my_size)
	{
		if (line[i] != 0)
		{
			line[j++] = line[i];
		}
		i++;
	}
	while (j < my_size)
	{
		line[j++] = 0;
	}
	/* merge to left*/
	i = 0;
	while (i < j)
	{
		if (line[i] == line[i + 1])
		{
			line[i] = line[i] + line[i + 1];
			/* shifting left next array elements */
			k = i + 1;
			while (k < j)
			{
				line[k] = line[k + 1];
				k++;
			}
			j--;
		}
		i++;
	}
	/* adding zeros right */
	while (j < my_size)
	{
		line[j++] = 0;
	}
}
/**
 * slide_line_right - Slides and merges an array of integers
 * @line: points to an lineay of integers containing size elements
 * that must be slided & merged
 * @my_size: size of the lineay of integers pointed by line
 * of integers. direction can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: nothing
 */
void slide_line_right(int *line, int my_size)
{
	int i, j, k;
	/* slide to right */
	j = my_size - 1;
	i = my_size - 1;
	while (i > -1)
	{
		if (line[i] != 0)
		{
			line[j--] = line[i];
		}
		i--;
	}
	while (j > -1)
	{
		line[j--] = 0;
	}
	/* merge to left*/
	i = my_size - 1;
	while (i > j)
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
		i--;
	}
	/* adding zeros left */
	while (j > -1)
	{
		line[j--] = 0;
	}
}

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
	int my_size;

	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
	{
		return (0);
	}

	my_size = (int) size;

	if (direction == 0)
	{
		slide_line_left(line, my_size);
	}
	if (direction == 1)
	{
		slide_line_right(line, my_size);
	}
	return (1);
}
