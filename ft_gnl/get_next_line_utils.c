/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:56:57 by mframbou          #+#    #+#             */
/*   Updated: 26-01-2022 14:05 by      /\  `-'/      `-'  '/   (  `-'-..`-'-' */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*gnl_ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = malloc (sizeof (char) * (i + 1));
	res[i] = '\0';
	while (--i >= 0)
		res[i] = str[i];
	return (res);
}
