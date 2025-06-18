/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:45:14 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 19:29:44 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_write_s(va_list args)
{
	int		len;
	char	*s;

	len = 0;
	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	if (*s)
	{
		while (*s)
		{
			write(1, s, 1);
			len++;
			s++;
		}
	}
	return (len);
}
