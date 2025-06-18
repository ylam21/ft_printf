/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:06:58 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 19:23:18 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	test_uint(unsigned int u)
{
	char	buffer_mine[1024];
	char	buffer_origin[1024];
	int		ret_mine;
	int		ret_origin;
	int		saved_stdout;
	size_t	len;
	int		fds[2];

	if (pipe(fds) == -1)
		return (-1);
	saved_stdout = dup(1);
	dup2(fds[1], 1);
	close(fds[1]);
	ret_mine = ft_printf("%u", u);
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
	ret_origin = printf("%u", u);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(fds[0], buffer_origin, sizeof(buffer_origin) - 1);
	buffer_origin[len] = '\0';
	close(fds[0]);
	if (ret_mine != ret_origin || strcmp(buffer_mine, buffer_origin) != 0)
	{
		printf("aim: %u / ret: %i\n", u, ret_origin);
		ft_printf("got: %u / ret: %i\n", u, ret_mine);
		return (1);
	}
	return (0);
}

int	main(void)
{
	unsigned int	tests[] = {0, UINT_MAX, 42, 99999, 4294967295U};
	int				i;
	int				size;

	i = 0;
	size = sizeof(tests) / sizeof(unsigned int);
	while (i < size)
	{
		if (test_uint(tests[i]) != 0)
		{
			printf("Test failed for %i\nfailed case uint: %u\n", i, tests[i]);
			return (i + 1);
		}
		i++;
	}
	printf("Test for '%%u' passed\n");
	return (0);
}
