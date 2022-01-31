/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:05:36 by mframbou          #+#    #+#             */
/*   Updated: 31-01-2022 17:23 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

/*
	Returns false if string is empty / not only +-/0-9
	cases like "" "-" "+" " 123"
*/
int	is_really_num(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if (str[i])
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;
	char	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] && \
	res >= -2147483648 && res <= 2147483647)
	{
		res *= 10;
		res += str[i++] - 48;
	}
	res *= sign;
	if ((str[i] && (str[i] < '0' || str[i] > '9')) || \
	(res < -2147483648 || res > 2147483647))
		return (999999999999L);
	return (res);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
