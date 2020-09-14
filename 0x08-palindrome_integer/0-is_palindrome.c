#include "palindrome.h"

/**
 * is_pal - Recursive function to help to check if
 * a given unsigned integer is a palindrome
 * @num: is the number to be checked
 * @res: partial number being checked
 * Return: 0 if num is 0 a recursive call to same function
 */

unsigned long is_pal(unsigned long num, unsigned long res)
{
	if (num == 0)
		return (res);

	res = 10 * res + num % 10;

	return (is_pal(num / 10, res));
}

/**
 * is_palindrome - Checks whether or not a
 * given unsigned integer is a palindrome
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long result;

	result = is_pal(n, 0);
	if (result == n)
		return (1);
	else
		return (0);
}
