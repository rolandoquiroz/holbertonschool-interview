#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: level of the menger sponge to draw
 *
 * Return: void
*/
void menger(int level)
{
	int i, j, height, width, size;
	char character;

	size = pow(3, level);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{;
			character = '#';
			height = i;
			width = j;
			while (height > 0)
			{
				if (height % 3 == 1 && width % 3 == 1)
					character = ' ';
				height /= 3;
				width /= 3;
			}
			printf("%c", character);
			j++;
		}
		printf("\n");
		i++;
	}
}
