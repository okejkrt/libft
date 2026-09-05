/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:54:06 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/02 09:54:39 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	sub_s = malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	ft_memcpy(sub_s, &s[start], len);
	sub_s[len] = '\0';
	return (sub_s);
}

// #include <stdio.h>

// int main(void)
// {
//     char *str1 = "Hello world!";

//     printf("Original: %s\n", ft_substr(str1, 6, 5));

//     return (0);
// }

