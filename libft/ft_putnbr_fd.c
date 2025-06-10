/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:34:24 by omaly             #+#    #+#             */
/*   Updated: 2025/06/04 20:39:41 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reversestr(char *str)
{
	int		str_len;
	char	tmp;
	int		pos;

	str_len = (int)ft_strlen(str);
	pos = 0;
	while (pos < (str_len / 2))
	{
		tmp = str[pos];
		str[pos] = str[str_len - pos - 1];
		str[str_len - pos - 1] = tmp;
		pos++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (9 < n)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
}
