/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:44:44 by omaly             #+#    #+#             */
/*   Updated: 2025/06/17 20:20:10 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_write_c(va_list args)
{
	unsigned int c;

	c = va_arg(args, unsigned int);

	return (write(1, &c, 1));
}
