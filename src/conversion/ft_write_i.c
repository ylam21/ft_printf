/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:56:24 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 19:57:22 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdarg.h>

int	ft_write_i(va_list args)
{
	int		value;
	char	*s;
	size_t	s_len;

	value = va_arg(args, int);
	s = ft_itoa(value);
	s_len = ft_strlen(s);
	write(1, s, s_len);
	free(s);
	return (s_len);
}
