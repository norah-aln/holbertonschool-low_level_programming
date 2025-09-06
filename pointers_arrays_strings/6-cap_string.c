#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to capitalize
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i, capitalize_next;

	capitalize_next = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' && capitalize_next)
		{
			str[i] = str[i] - 32;
			capitalize_next = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			capitalize_next = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			capitalize_next = 0;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			str[i] == '}')
		{
			capitalize_next = 1;
		}
		else
		{
			capitalize_next = 0;
		}
	}
	return (str);
}
