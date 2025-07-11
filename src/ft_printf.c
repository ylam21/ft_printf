/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:23 by omaly             #+#    #+#             */
/*   Updated: 2025/07/09 22:27:50 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "conversion/ft_print_utils.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_is_in_set(char c)
{
	return (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X');
}

int	ft_handle_valid_specifier(va_list args, char c)
{
	if (c == '%')
		return (write(1, &c, 1));
	else if (c == 'c')
		return (ft_write_c(args));
	else if (c == 's')
		return (ft_write_s(args));
	else if (c == 'p')
		return (ft_write_p(args));
	else if (c == 'd' || c == 'i')
		return (ft_write_d(args));
	else if (c == 'u')
		return (ft_write_u(args));
	else if (c == 'x')
		return (ft_write_x(args));
	else if (c == 'X')
		return (ft_write_upx(args));
	else
		return (0);
}

int	ft_handle_percent(const char *format, int *i, va_list args)
{
	int	ret;

	ret = 0;
	if (format[*i + 1] == '\0' || (ft_is_in_set(format[*i + 1]) == 0
			&& ft_isprint(format[*i + 1])))
		return (-1);
	else if (ft_is_in_set(format[*i + 1]))
	{
		ret += ft_handle_valid_specifier(args, format[*i + 1]);
		(*i)++;
	}
	else if (ft_isprint(format[*i + 1]) == 0)
	{
		ret += write(1, &format[*i], 1);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		t_len;
	int		i;
	int		ret;
	va_list	args;

	t_len = 0;
	i = 0;
	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret = ft_handle_percent(format, &i, args);
			if (ret == -1)
			{
				va_end(args);
				return (-1);
			}
			t_len += ret;
			i++;
		}
		else
			t_len += write(1, &format[i++], 1);
	}
	va_end(args);
	return (t_len);
}
