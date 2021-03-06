#include "sandpiles.h"

static void print_grid(int grid[3][3]);
/**
 * sandpiles_sum - Computes the sum of two sandpiles
 *
 * @grid1: Sandpile to be summed
 * @grid2: Sandpile to be summed
 *
 * Return: A sandpile with the sum of grid1 and grid2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int big[5][5];
	int unstable;

	unstable = 0;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			grid1[i - 1][j - 1] += grid2[i - 1][j - 1];
			if (grid1[i - 1][j - 1] > 3)
				unstable = 1;
			big[i][j] = grid1[i - 1][j - 1];
		}
	}

	while (unstable)
	{
		unstable = 0;
		for (i = 1; i <= 3; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				if (grid1[i - 1][j - 1] > 3)
				{
					unstable = 1;
					big[i - 1][j] += 1;
					big[i + 1][j] += 1;
					big[i][j - 1] += 1;
					big[i][j + 1] += 1;
					big[i][j] -= 4;
				}
			}
		}

		if (unstable)
			print_grid(grid1);

		for (i = 1; i <= 3; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				grid1[i - 1][j - 1] = big[i][j];
			}
		}
	}
}

/**
* print_grid - Prints a 3 by 3 grid.
* @grid: Grid to be printed.
*/

static void print_grid(int grid[3][3])
{
	int i, j;

	puts("=");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
