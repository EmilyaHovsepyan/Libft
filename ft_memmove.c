/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:04:15 by ehovsepy          #+#    #+#             */
/*   Updated: 2025/01/31 13:29:31 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_backward(char *d, const char *s, size_t len)
{
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		return (ft_memmove_backward(d, s, len));
	}
	return (dst);
}
