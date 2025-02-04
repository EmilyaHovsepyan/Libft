/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:25:41 by ehovsepy          #+#    #+#             */
/*   Updated: 2025/02/02 10:08:02 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret++;
			while (*s && *s != c)
				s++;
		}
		else
			++s;
	}
	return (ret);
}

static char	*ft_process_word(const char **s, char c, size_t *len)
{
	while (**s && **s != c)
	{
		(*len)++;
		(*s)++;
	}
	return (ft_substr(*s - *len, 0, *len));
}

static void	*ft_free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			ret[i] = ft_process_word(&s, c, &len);
			if (!ret[i])
				return (ft_free_all(ret, i));
			i++;
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
