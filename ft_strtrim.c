/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:24:51 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/02 09:52:02 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s;
	size_t	start;
	size_t	end;
	size_t	len;
	
	if (!s1 || !set)
    	return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed_s = malloc(len + 1);
	if (trimmed_s == NULL)
		return (NULL);
	ft_memcpy(trimmed_s, &s1[start], len);
	trimmed_s[len] = '\0';
	return (trimmed_s);
}

#include <stdio.h>

int	main(void)
{
	char	*s1 = "   ---Hello World!---   ";
	char	*set = " -";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}