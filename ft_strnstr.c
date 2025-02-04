/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by ehovsepy          #+#    #+#             */
/*   Updated: 2025/01/31 11:41:28 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	b_len;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	b_len = ft_strlen(needle);
	if (b_len == 0 || haystack == needle)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] != '\0' && needle[j] != '\0'
			&& hay[i + j] == needle[j] && i + j < len)
			j++;
		if (j == b_len)
			return (hay + i);
		i++;
	}
	return (0);
}
