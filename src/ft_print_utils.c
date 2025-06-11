#include <stdarg.h>
#include <unistd.h>

int ft_write_c(va_list args)
{
	char c = va_arg(args, int);
	return (write(1,&c,1));
}

int ft_write_s(va_list args)
{
	int len = 0;
	char *s = va_arg(args, char *);
	if (s && *s)
	{
		while (*s)
		{
			write(1,s,1);
			len++;
			s++;
		}
	}
	return len;
}

int ft_write_p(va_list args)
{
	(void)args;
	return 1;
}

int ft_write_d(va_list args)
{
	(void)args;
	return 1;
}

int ft_write_i(va_list args)
{
	(void)args;
	return 1;
}

int ft_write_x(va_list args)
{
	(void)args;
	return 1;
}

int ft_write_X(va_list args)
{
	(void)args;
	return 1;
}

int ft_write_u(va_list args)
{
	(void)args;
	return 1;
}
