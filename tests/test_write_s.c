/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:35:19 by omaly             #+#    #+#             */
/*   Updated: 2025/07/02 12:38:57 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	test_string(char *s)
{
	int		pipefd[2];
	char	buffer_mine[1024] = {0};
	char	buffer_origin[1024] = {0};
	int		saved_stdout;
	int		ret_mine;
	size_t	len;
	int		ret_origin;

	if (pipe(pipefd) == -1)
		return (1);
	saved_stdout = dup(1);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	ret_mine = ft_printf("%s", s);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(pipefd[0], buffer_mine, sizeof(buffer_mine) - 1);
	buffer_mine[len] = '\0';
	close(pipefd[0]);
	if (pipe(pipefd) == -1)
		return (2);
	saved_stdout = dup(1);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	ret_origin = printf("%s", s);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	len = read(pipefd[0], buffer_origin, sizeof(buffer_origin) - 1);
	buffer_origin[len] = '\0';
	close(pipefd[0]);
	if (ret_mine != ret_origin || strcmp(buffer_mine, buffer_origin) != 0)
	{
		printf("Test failed for %s\n", s);
		return (3);
	}
	return (0);
}

int	main(void)
{
	char	*tests[] = {"", "\0", "hello", NULL, "string with % in it",
			"long string: Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
			"he\nll\to"};
	int		i;
	int		tests_count;

	i = 0;
	tests_count = sizeof(tests) / sizeof(char *);
	while (i < tests_count)
	{
		if (test_string(tests[i]) != 0)
			return (i + 1);
		i++;
	}
	printf("Test for '%%s' passed\n");
	return (0);
}
