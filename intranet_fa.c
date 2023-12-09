#include <stdio.h>
#include <string.h>

/**
 * main - Entry point main
 *
 * Return: 0
 */
int main(void)
{
	char str[] = "ADBazerds qazertyuio pmlkjhgf dsqwxcvbn ,;ù";
	int i = 0;
	int len = 0;
	int cnt = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			putchar(str[i]);
			cnt++;
		}
		if (cnt > 0 || str[i] < str[cnt])
		{
			putchar(',');
			putchar(' ');
		}
	}
	if (cnt == len)
		printf("\nThe number of alphabet is %d\n", cnt);

	return (0);
}
