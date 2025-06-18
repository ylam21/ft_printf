/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:03:39 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 20:29:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	test_hex(unsigned int x)
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
	ret_mine = ft_printf("%x", x);
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
	ret_origin = printf("%x", x);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(fds[0], buffer_origin, sizeof(buffer_origin) - 1);
	buffer_origin[len] = '\0';
	close(fds[0]);
	if (ret_mine != ret_origin || strcmp(buffer_mine, buffer_origin) != 0)
	{
		printf("aim: %x / ret: %i\n", x, ret_origin);
		ft_printf("mine: %x / ret: %i\n", x, ret_mine);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	i;
	int	size;

	unsigned int tests[] = {
		0,
		UINT_MAX,
		42,
		99999,
		4294967295U,
		0xABCDEF,
		0xabcdef,
	};
	i = 0;
	size = sizeof(tests) / sizeof(unsigned int);
	while (i < size)
	{
		if (test_hex(tests[i]) != 0)
		{
			printf("Test failed for %i\nfailed case uint: %u\n", i, tests[i]);
			return (i + 1);
		}
		i++;
	}
	printf("Test for '%%x' passed\n");
	return (0);
}
