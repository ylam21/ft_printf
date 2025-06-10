/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:35:47 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:35:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;
	size_t	pos;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
		return (NULL);
	pos = 0;
	while (pos < s1_len)
	{
		join[pos] = s1[pos];
		pos++;
	}
	pos = 0;
	while (pos < s2_len)
	{
		join[s1_len + pos] = s2[pos];
		pos++;
	}
	join[s1_len + pos] = '\0';
	return (join);
}
