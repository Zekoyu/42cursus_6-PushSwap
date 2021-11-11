/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:05:36 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/10 19:56:11 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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
		res += str[i] - 48;
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9' || \
	res < -2147483648 || res > 2147483647))
		return (999999999999L);
	return (res * sign);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
