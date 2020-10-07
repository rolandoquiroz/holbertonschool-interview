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
	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
	{
		return (0);
	}

	if (direction == 0)
	{


	}

	if (direction == 1)

	return (1);
}
