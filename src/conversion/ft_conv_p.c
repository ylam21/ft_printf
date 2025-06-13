/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:08:20 by omaly             #+#    #+#             */
/*   Updated: 2025/06/13 13:36:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_write_p(va_list args)
{
	void *ptr = va_arg(args,void *);
	static const char *table = "123456789abcdef";

	unsigned long long value = (unsigned long long)ptr;

	char buffer[sizeof(void *) * 2];

	int i = 0;

	while (value)
	{
		int	digit = value % 16;
		buffer[i++] = table[digit];
		value /= 16;
	}

	while (i < (int)sizeof(buffer))
	{
		buffer[i++] = '0';
	}

	int len = 0;

	while (i--)
	{
		write(1,buffer - i,1);
		len++;
	}

	return len;
}

