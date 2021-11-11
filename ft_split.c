/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:15:28 by mframbou          #+#    #+#             */
/*   Updated: 2021/11/09 15:04:30 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*clean_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	return (NULL);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substr = (char *) malloc(sizeof (char));
		if (substr)
			*substr = '\0';
		return (substr);
	}
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (substr)
	{
		i = 0;
		while (i < len && s[i])
			substr[i++] = s[start++];
		substr[i] = '\0';
	}
	return (substr);
}

static int	get_substring_count(char const *str, char c)
{
	int		str_count;
	size_t	i;

	str_count = 0;
	i = 0;
	while (str[i])
	{
		i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i != 0 && str[i - 1] != c)
			str_count++;
	}
	return (str_count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		substr_count;
	int		i;
	size_t	j;
	size_t	substr_start;

	i = -1;
	j = 0;
	substr_count = get_substring_count(s, c);
	res = malloc (sizeof (char *) * (substr_count + 1));
	if (!res)
		return (NULL);
	while (++i < substr_count)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		substr_start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		res[i] = ft_substr(s, substr_start, (j - substr_start));
		if (!res[i])
			return (clean_array(res));
	}
	res[i] = 0;
	return (res);
}
