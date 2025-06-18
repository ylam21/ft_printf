/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:02:19 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 20:23:54 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	ft_write_uphex(unsigned long long value, const char *table)
{
	int		i;
	int		digit;
	int		len;
	char	buffer[sizeof(void *) * 2];

	if (value == 0)
		return (write(1, "0", 1));
	i = 0;
	while (value)
	{
		digit = value % 16;
		buffer[i++] = table[digit];
		value /= 16;
	}
	len = 0;
	while (i--)
	{
		write(1, &buffer[i], 1);
		len++;
	}
	return (len);
}

int	ft_write_upx(va_list args)
{
	unsigned int		value;
	static const char	*table = "0123456789ABCDEF";

	value = va_arg(args, unsigned int);
	return (ft_write_uphex(value, table));
}
