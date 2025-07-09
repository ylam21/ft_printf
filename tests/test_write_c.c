/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:34:57 by omaly             #+#    #+#             */
/*   Updated: 2025/07/09 21:42:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	test_char(int c)
{
	int		pipefd[2];
	char	buffer_mine[2] = {0};
	char	buffer_origin[2] = {0};
	int		saved_stdout;
	int		ret_mine;
	int		ret_origin;

	if (pipe(pipefd) == -1)
		return (1);
	saved_stdout = dup(1);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	ret_mine = ft_printf("%c", c);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	read(pipefd[0], buffer_mine, 1);
	close(pipefd[0]);
	if (pipe(pipefd) == -1)
		return (2);
	saved_stdout = dup(1);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	ret_origin = printf("%c", c);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	read(pipefd[0], buffer_origin, 1);
	close(pipefd[0]);
	if (ret_mine != ret_origin || buffer_mine[0] != buffer_origin[0])
	{
		printf("expected: %s\ngot: %s\n",buffer_origin,buffer_mine);
		printf("expected: %i\ngot: %i\n",ret_origin,ret_mine);
		printf("Test failed for %d\n", c);
		return (3);
	}
	return (0);
}

int	main(void)
{
	unsigned int	limit;
	unsigned int	c;

	limit = 256;
	c = 0;
	while (c < limit)
	{
		if (test_char(c++) != 0)
			return (1);
	}
	printf("Test for '%%c' passed\n");
	return (0);
}
