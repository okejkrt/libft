/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:57:52 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/07 17:26:46 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_numlen(nb);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	str[len] = (nb % 10) + '0';
	return (str);
}
