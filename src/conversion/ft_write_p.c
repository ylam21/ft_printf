/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:08:20 by omaly             #+#    #+#             */
/*   Updated: 2025/06/13 16:13:26 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_write_p(va_list args)
{
	static const char *table = "123456789abcdef";

	void *ptr = va_arg(args,void *);

	if (!ptr)
		return write(1,"(nil)",5);

	unsigned long long value = (unsigned long long)ptr;
	char buffer[sizeof(void *) * 2];

	int i = 0;
	while (value)
	{
		int	digit = value % 16;
		buffer[i++] = table[digit - 1];
		value /= 16;
	}

	write(1,"0x",2);
	int len = 2;
	while (i--)
	{
		write(1,&buffer[i],1);
		len++;
	}

	return len;
}

