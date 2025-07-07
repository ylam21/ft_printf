/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:48:14 by omaly             #+#    #+#             */
/*   Updated: 2025/07/02 12:38:29 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	test_percent(void)
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
	ret_mine = ft_printf("%%");
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
	ret_origin = printf("%%");
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
	if (test_percent() != 0)
		return (1);
	printf("Test for PERCENT passed\n");
	return (0);
}
