#include "main.h"

int convert_S(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j;
	int num;
	char *hex;
	int k;

	str = va_arg(args, char *);
	for (j = 0; str[j] != '\0'; j++)
	{
		if ((str[j] > 0 && str[j] < 32) || str[j] >= 127)
		{
			buffer[buffer_index++] = '\\';
			buffer[buffer_index++] = 'x';
			num = str[j];
			hex = _itoa(num, 16, 1);
			if (_strlen(hex) == 1)
				buffer[buffer_index++] = '0';
			for (k = 0; hex[k] != '\0'; k++)
				buffer[buffer_index++] = hex[k];
			free(hex);
		}
		else
			buffer[buffer_index++] = str[j];
	}
	return (buffer_index);
}
