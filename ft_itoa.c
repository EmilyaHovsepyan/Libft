/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:50:28 by ehovsepy          #+#    #+#             */
/*   Updated: 2025/01/30 11:13:04 by ehovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_hold;
	size_t		digits;
	long int	num;

	num = n;
	digits = digit_count(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_hold = malloc(digits + 1);
	if (!str_hold)
		return (NULL);
	str_hold[digits] = '\0';
	while (digits > 0)
	{
		digits--;
		str_hold[digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str_hold[0] = '-';
	return (str_hold);
}
