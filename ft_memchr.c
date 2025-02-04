/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:58:00 by ehovsepy          #+#    #+#             */
/*   Updated: 2025/01/30 11:17:51 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*fet;
	unsigned char	bullet;

	fet = (unsigned char *)s;
	i = 0;
	bullet = (unsigned char)c;
	while (i < n)
	{
		if (*fet == bullet)
			return (fet);
		fet++;
		i++;
	}
	return (NULL);
}
