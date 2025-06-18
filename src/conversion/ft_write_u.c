/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:02:19 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 19:29:49 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_uintlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nb)
{
	int		len;
	char	*str;

	len = ft_uintlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int	ft_write_u(va_list args)
{
	unsigned int	value;
	char			*s;
	size_t			s_len;

	value = va_arg(args, unsigned int);
	s = ft_uitoa(value);
	s_len = ft_strlen(s);
	write(1, s, s_len);
	free(s);
	return (s_len);
}
