/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 21:32:02 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/02 09:08:58 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;
	
	last_c = NULL;
	while (1)
	{
		if ((unsigned char)*s == (unsigned char)c)		
			last_c = (char *)s;
		if (*s == '\0')		
			return (last_c);
		s++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = "abcdefabcdefa";
// 	char	c = 'a';
// 	char	*ptr;
	
// 	ptr = ft_strrchr(str, c);
// 	printf("%s\n", ptr);
// 	return (0);
// }
