/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:32:45 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/26 13:44:37 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	
	i = 0;
	while (dst[i])
		i++;
	if (i < size)
	{
		while (*src && i < (size - 1))
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}

int main(void)
{
    char dest[13] = "Hello ";
    char src[] = "world!";
	size_t	len;

    len = ft_strlcat(dest, src, 13);
    printf("%s\n%zu\n", dest, len);

    return (0);
}

