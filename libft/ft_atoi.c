/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:01:11 by omaly             #+#    #+#             */
/*   Updated: 2025/06/03 15:26:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isdigit(int c);

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_getstartidx(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != 0)
	{
		if (!ft_isspace(s[idx]))
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi(const char *s)
{
	int	start_pos;
	int	pos;
	int	sign;
	int	acc;

	start_pos = ft_getstartidx(s);
	if (start_pos == -1)
		return (0);
	pos = start_pos;
	sign = 0;
	if (s[pos] == '-' || s[pos] == '+')
	{
		if (s[pos] == '-')
			sign = 1;
		pos++;
	}
	acc = 0;
	while (s[pos] != 0 && ft_isdigit(s[pos]))
	{
		acc = acc * 10 + s[pos] - '0';
		pos++;
	}
	if (sign)
		return (acc * -1);
	return (acc);
}
