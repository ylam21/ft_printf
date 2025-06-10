/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:32:30 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:32:39 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*_src;
	unsigned char		*_dest;

	if ((src < dest) && (src + n >= dest))
	{
		_src = src + n - 1;
		_dest = dest + n - 1;
		while (n--)
		{
			*_dest-- = *_src--;
		}
	}
	else
	{
		_src = src;
		_dest = dest;
		while (n--)
		{
			*_dest++ = *_src++;
		}
	}
	return (dest);
}
