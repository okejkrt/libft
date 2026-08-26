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
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;
	
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	total_len = dst_len + src_len;
	while (*src && dst_len < (size - 1))
	{
		dst[dst_len] = *src++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (total_len);
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

