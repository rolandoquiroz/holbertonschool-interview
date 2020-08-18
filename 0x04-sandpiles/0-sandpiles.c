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
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
			{
				unstable = 1;
			}
		}
	}

	while (unstable)
	{
		print_grid(grid1);
		unstable = 0;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((i > 0 && i < 4) && (j > 0 && j < 4))
					big[i][j] = grid1[i - 1][j - 1];
				else
					continue;
			}
		}

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((i > 0 && i < 4) && (j > 0 && j < 4))
				{
					if (grid1[i - 1][j - 1] > 3)
					{
						big[i - 1][j] += 1;
						big[i + 1][j] += 1;
						big[i][j - 1] += 1;
						big[i][j + 1] += 1;
						big[i][j] -= 4;
					}
				}
				else
					continue;
			}
		}

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((i > 0 && i < 4) && (j > 0 && j < 4))
				{
					grid1[i - 1][j - 1] = big[i][j];
					if (grid1[i - 1][j - 1] > 3)
						unstable = 1;
				}
				else
					continue;
			}
		}

		if (unstable == 0)
			break;
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
