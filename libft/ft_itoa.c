/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:29:48 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 16:07:11 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int num)
{
	int	len;

	len = (num <= 0);
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	int		len;
	long	nb;
	char	*str;

	len = ft_intlen(num);
	nb = num;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (len == 0)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
