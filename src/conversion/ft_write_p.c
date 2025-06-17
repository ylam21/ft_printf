/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:08:20 by omaly             #+#    #+#             */
/*   Updated: 2025/06/17 22:34:28 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_write_hex(unsigned long long value, const char *table)
{
	int		i;
	int		digit;
	int		len;
	char	buffer[sizeof(void *) * 2];

	if (value == 0)
		return (write(1, "0x0", 3));
	i = 0;
	while (value)
	{
		digit = value % 16;
		buffer[i++] = table[digit];
		value /= 16;
	}
	write(1, "0x", 2);
	len = 2;
	while (i--)
	{
		write(1, &buffer[i], 1);
		len++;
	}
	return (len);
}

int	ft_write_p(va_list args)
{
	static const char	*table = "0123456789abcdef";
	void				*ptr;
	unsigned long long	value;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	value = (unsigned long long)ptr;
	return (ft_write_hex(value, table));
}
