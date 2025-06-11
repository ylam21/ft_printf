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
