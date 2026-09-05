/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:13:38 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/27 13:08:00 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	
	ptr = (unsigned char*)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)		
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

#include <stdio.h>

int main(void)
{
    char dest[] = "abcde";

    printf("%s\n", (char *)ft_memchr(dest, 'c', 3));

    return (0);
}