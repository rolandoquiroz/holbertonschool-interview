#include "holberton.h"

/**
 * _isdigit - function that checks for a digit (0 through 9).
 * @c: int c
 * Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(char c)
{
	int ret;

	if (c > 47 && c < 58)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return (ret);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: char *s1
 * @s2: char *s2
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((*s1) - (*s2));
}

/**
 * _strlen - function that returns the length of a string.
 * @s: char *s String to be processed
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		++len;
	}
	return (len);
}

/**
 * _memset - Function that fills memory with a constant byte.
 * @s: char *dest
 * @b: char *src
 * @n: unsigned int n
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while ((n--) > 0)
		*ptr++ = b;
	return (s);
}

/**
 * _memmove - Function to copy block of 'n' bytes from source
 * address 'src' to destination address 'dest'
 * @dest: char *dest
 * @src: char *src
 * @n: unsigned int n
 * Return: char
 */
void _memmove(void *dest, void *src, int n)
{
	int i;
	char *psrc = (char *)src;
	char *pdest = (char *)dest;
	char *temp;

	temp = (char *)malloc(n * sizeof(char));

	for (i = 0; i < n; i++)
		*(temp + i) = *(psrc + i);

	for (i = 0; i < n; i++)
		*(pdest + i) = *(temp + i);

	free(temp);
}

/**
 * error - Function to print error and exit 98.
 * Return: Nothing (void)
 */
void error(void)
{
	int i;
	char err[] = "Error\n";

	for (i = 0; i <= 5; i++)
	{
		_putchar(err[i]);
	}
	exit(98);
}

/**
 * longmulti - Function to copy block of 'n' bytes from source
 * address 'src' to destination address 'dest'
 * @a: char *dest
 * @b: char *src
 * @c: unsigned int n
 * Return: char
 */
void longmulti(char *a, char *b, char *c)
{
	int i = 0, j = 0, k = 0, n, carry;
	int la, lb;

	if (!_strcmp(a, "0") || !_strcmp(b, "0"))
	{
		c[0] = '0', c[1] = '\0';
		return;
	}

	la = _strlen(a);
	lb = _strlen(b);
	_memset(c, '0', la + lb);
	c[la + lb] = '\0';

	#define I(a) (a - '0')
	for (i = la - 1; i >= 0; i--)
	{
		for (j = lb - 1, k = i + j + 1, carry = 0; j >= 0; j--, k--)
		{
			n = I(a[i]) * I(b[j]) + I(c[k]) + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
		}
		c[k] += carry;
	}
	#undef I
	if (c[0] == '0')
		_memmove(c, c + 1, la + lb);
}

/**
 * main - prints buffer in hexa
 * @argc: the address of memory to print
 * @argv: the size of the memory to print
 * Return: Nothing.
 */
int main(int argc, char *argv[])
{
	char c[10240];
	int i;

	if (argc != 3)
		error();

	i = 0;
	while ((argv[1])[i] != '\0')
	{
		if (_isdigit((argv[1])[i]))
			i++;
		else
			error();
	}

	i = 0;
	while ((argv[2])[i] != '\0')
	{
		if (_isdigit((argv[2])[i]))
			i++;
		else
			error();
	}

	longmulti(argv[1], argv[2], c);

	i = 0;
	while (c[i] == '0' && c[i + 1] != '\0')
	{
		i++;
	}

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
