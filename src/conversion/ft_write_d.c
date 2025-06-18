/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:52:19 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 17:30:13 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdarg.h>

int	ft_write_d(va_list args)
{
	int		value;
	char	*s;
	size_t	s_len;
	size_t	i;

	value = va_arg(args, int);
	s = ft_itoa(value);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
		write(1, &s[i++], 1);
	return (s_len);
}
