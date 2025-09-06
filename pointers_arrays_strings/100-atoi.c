#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to string
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i, sign, result;
	int started;

	i = 0;
	sign = 1;
	result = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
		{
			/* Keep current sign */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			/* Check for overflow before multiplication */
			if (result > (2147483647 / 10) ||
				(result == 214748364 && (s[i] - '0') > 7))
			{
				if (sign == 1)
					return (2147483647);
				else
					return (-2147483648);
			}
			result = result * 10 + (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	return (result * sign);
}
