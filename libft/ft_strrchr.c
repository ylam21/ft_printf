/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:16 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:37:28 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*_s;

	_s = NULL;
	if (c == 0 && *s == 0)
		return ((char *)s);
	while (s && *s != 0)
	{
		if (*s == (char)c)
		{
			_s = (char *)s;
		}
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (_s);
}
