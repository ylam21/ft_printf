/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:11 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:38:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*_s;

	_s = (unsigned char *)s;
	while (n--)
	{
		if (*_s++ == (unsigned char)c)
			return (--_s);
	}
	return (NULL);
}
