/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:29:20 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/02 09:09:39 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if ((unsigned char)*s == (unsigned char)c)		
			return ((char *)s);
		if (*s == '\0')		
			return (NULL);
		s++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = "abcde";
// 	char	c = '\0';
// 	char	*ptr;
	
// 	ptr = ft_strchr(str, c);
// 	printf("%s\n", ptr);
// 	return (0);
// }