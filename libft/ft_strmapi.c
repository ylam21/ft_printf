/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:46 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:36:48 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	mapi_len;
	char	*mapi;
	int		i;

	if (!s || !f)
		return (NULL);
	mapi_len = ft_strlen(s);
	mapi = (char *)malloc(sizeof(char) * mapi_len + 1);
	if (!mapi)
		return (NULL);
	mapi[mapi_len] = '\0';
	i = 0;
	while (i < (int)mapi_len)
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	return (mapi);
}
