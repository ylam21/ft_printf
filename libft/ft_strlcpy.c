/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:16 by omaly             #+#    #+#             */
/*   Updated: 2025/06/04 20:51:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*_src;
	size_t	len;

	_src = (char *)src;
	len = 0;
	if (size > 0)
	{
		while (len < size - 1 && *src)
		{
			*dst++ = *src++;
			len++;
		}
		*dst = 0;
	}
	len = ft_strlen(_src);
	return (len);
}
