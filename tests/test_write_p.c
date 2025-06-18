/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:35:09 by omaly             #+#    #+#             */
/*   Updated: 2025/06/18 17:37:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int test_pointer(void *p)
{
	int pipefd[2];

	char buffer_mine[1024] = {0};
	char buffer_origin[1024] = {0};

	int saved_stdout;

	if (pipe(pipefd) == -1)
		return 1;

	saved_stdout = dup(1);
	dup2(pipefd[1],1);
	close(pipefd[1]);

	int ret_mine = ft_printf("%p",p);
	fflush(stdout);
	dup2(saved_stdout,1);
	close(saved_stdout);

	size_t len = read(pipefd[0],buffer_mine,sizeof(buffer_mine) - 1);
	buffer_mine[len] = '\0';
	close(pipefd[0]);

	if (pipe(pipefd) == -1)
		return 2;

	saved_stdout = dup(1);
	dup2(pipefd[1],1);
	close(pipefd[1]);

	int ret_origin = printf("%p",p);
	fflush(stdout);
	dup2(saved_stdout,1);
	close(saved_stdout);

	len = read(pipefd[0],buffer_origin,sizeof(buffer_origin) - 1);
	buffer_origin[len] = '\0';
	close(pipefd[0]);

	if (ret_mine != ret_origin || strcmp(buffer_mine,buffer_origin) != 0)
	{
		printf("Test failed for %p\n", p);
		printf("aim: %p\ngot: %p\n",buffer_origin, buffer_mine);
		printf("aim_ret: %d\ngot_ret: %d\n",ret_origin,ret_mine);
		return 3;
	}

	return 0;
}


int main (void)
{
	int x = 42;
	void *heap_ptr = malloc(1);
	if (!heap_ptr)
		{
			printf("Error with malloc\n");
			return 1;
		}
	void *null_ptr = NULL;

	void *tests[] = {
		&x,
		heap_ptr,
		null_ptr,
		&main,
		&test_pointer,
	};

	int i = 0;
	int tests_count = sizeof(tests)/sizeof(void *);
	while (i < tests_count)
	{
		if (test_pointer(tests[i]) != 0)
			return i + 2;
		i++;
	}

	free(heap_ptr);

	printf("Test for '%%p' passed\n");
	return 0;
}
