#include "main.h"

/**
 * times_table - prints the 9 times table
 */
void times_table(void)
{
	int row = 0;
	int col;
	int result;

	while (row <= 9)
	{
		col = 0;
		while (col <= 9)
		{
			result = row * col;
			
			if (col == 0)
			{
				_putchar(result + '0');
			}
			else if (result < 10)
			{
				_putchar(',')
				_putchar(' ')
				_putchar(' ')
				_putchar(result + '0');
			}
			else
			{
				_putchar(',')
				_putchar(' ')
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
			col++;
		}
		_putchar('
');
		row++;
	}
}
