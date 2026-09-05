/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:43:41 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/01 17:23:11 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_len;

	if (!s1 || !s2)
    	return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2;
	joined_s = malloc(total_len + 1);
	if (joined_s == NULL)
		return (NULL);
	ft_memcpy(joined_s, s1, len_s1);
	ft_memcpy(&joined_s[len_s1], s2, len_s2);
	joined_s[total_len] = '\0';
	return (joined_s);
}
