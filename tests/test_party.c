/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_party.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:40:08 by omaly             #+#    #+#             */
/*   Updated: 2025/07/02 12:38:23 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	test_party(char *str, char c, int d, int i, void *ptr, char *s,
		unsigned int u, unsigned int x, unsigned int X)
{
	char	buffer_mine[1024];
	char	buffer_origin[1024];
	int		ret_mine;
	int		ret_origin;
	size_t	len;
	int		saved_stdout;
	int		fds[2];

	if (pipe(fds) == -1)
		return (-1);
	saved_stdout = dup(1);
	dup2(fds[1], 1);
	close(fds[1]);
	ret_mine = ft_printf(str, c, d, i, ptr, s, u, x, X);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(fds[0], buffer_mine, sizeof(buffer_mine) - 1);
	buffer_mine[len] = '\0';
	close(fds[0]);
	if (pipe(fds) == -1)
		return (-1);
	saved_stdout = dup(1);
	dup2(fds[1], 1);
	close(fds[1]);
	ret_origin = printf(str, c, d, i, ptr, s, u, x, X);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(fds[0], buffer_origin, sizeof(buffer_origin) - 1);
	buffer_origin[len] = '\0';
	close(fds[0]);
	if (ret_mine != ret_origin || strcmp(buffer_mine, buffer_origin) != 0)
	{
		printf("expected: /%s/\n", buffer_origin);
		ft_printf("got: /%s/\n", buffer_mine);
		return (1);
	}
	return (0);
}

int	main(void)
{
	char			c;
	int				d;
	int				i;
	void			*ptr;
	char			*s;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	char			*test;

	// values
	c = 'a';
	d = 0;
	i = 42;
	ptr = NULL;
	s = "Hello";
	u = 0;
	x = 13;
	X = 14;
	test = "%c%d%i%p%s%u%X%x%";
	if (test_party(test, c, d, i, ptr, s, u, x, X) != 0)
		return (1);
	printf("Test for PARTY passed\n");
	return (0);
}
