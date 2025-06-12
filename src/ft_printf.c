/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:23 by omaly             #+#    #+#             */
/*   Updated: 2025/06/12 13:52:49 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./conversion/ft_print_utils.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_handle_per_cent(va_list args, char c)
{
	if (c == '%')
		return (write(1, &c, 1));
	else if (c == 'c')
		return (ft_write_c(args));
	else if (c == 's')
		return (ft_write_s(args));
	else if (c == 'p')
		return (ft_write_p(args));
	else if (c == 'd')
		return (ft_write_d(args));
	else if (c == 'i')
		return (ft_write_i(args));
	else if (c == 'u')
		return (ft_write_u(args));
	else if (c == 'x')
		return (ft_write_x(args));
	else if (c == 'X')
		return (ft_write_X(args));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;

	t_len = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			t_len += ft_handle_per_cent(args, *format);
		}
		else
			t_len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (t_len);
}
