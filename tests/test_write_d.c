/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:59 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 17:38:01 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "../ft_printf.h"

int test_decimal(int d)
{
	char buffer_mine[1024];
	char buffer_origin[1024];
	int ret_mine;
	int ret_origin;

	int saved_stdout;
	int fds[2];

	if (pipe(fds) == -1)
		return -1;

	saved_stdout = dup(1);
	dup2(fds[1],1);
	close(fds[1]);

	ret_mine = ft_printf("%d",d);
	fflush(stdout);
	dup2(saved_stdout,1);
	close(saved_stdout);

	size_t len;
	len = read(fds[0],buffer_mine,sizeof(buffer_mine) - 1);
	buffer_mine[len] = '\0';
	close(fds[0]);

	if (pipe(fds) == -1)
		return -1;

	saved_stdout = dup(1);
	dup2(fds[1], 1);
	close(fds[1]);

	ret_origin = printf("%d", d);
	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);

	len = read(fds[0], buffer_origin, sizeof(buffer_origin) -1);
	buffer_origin[len] = '\0';
	close(fds[0]);

	if (ret_mine != ret_origin || strcmp(buffer_mine,buffer_origin) != 0)
	{
		ft_printf("got: %d\n",d);
		printf("aim: %d\n",d);
		return 1;
	}
	return 0;
}

int main(void)
{
	int tests[] = {
		0,
		INT_MIN,
		INT_MAX,
		42,
		-1,
		123456789
	};

	int i = 0;
	int size = sizeof(tests)/sizeof(int);
	while (i < size)
	{
		if (test_decimal(tests[i]) != 0)
		{
			printf("Case: %d failed\n",i);
			return i + 1;
		}
		i++;
	}
	printf("Test for '%%d' passed\n");
	return 0;
}
