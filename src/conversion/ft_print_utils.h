/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:36:46 by omaly             #+#    #+#             */
/*   Updated: 2025/06/12 13:37:36 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_UTILS_H
# define FT_PRINT_UTILS_H
# include <stdarg.h>
int	ft_write_c(va_list args);
int	ft_write_s(va_list args);
int	ft_write_p(va_list args);
int	ft_write_d(va_list args);
int	ft_write_i(va_list args);
int	ft_write_u(va_list args);
int	ft_write_x(va_list args);
int	ft_write_X(va_list args);
#endif
