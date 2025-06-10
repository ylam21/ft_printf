/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:12 by omaly             #+#    #+#             */
/*   Updated: 2025/06/04 19:20:14 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	size_t	i;

	if (!haystack || !needle)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len > n)
		return (NULL);
	if (needle_len == 0)
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] != '\0' && (i + needle_len) <= n)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
