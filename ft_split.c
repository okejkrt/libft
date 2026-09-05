/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:04:57 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/02 12:29:54 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitcount(char const *s, char c)
{
	size_t	num_s;
	size_t	i;

	num_s = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_s++;
		i++;
	}
	return (num_s);
}

size_t	ft_splitlen(char const *s, char c)
{
	size_t	len_s;

	len_s = 0;
	while (s[len_s] && s[len_s] != c)
		len_s++;
	return (len_s);
}

char	**ft_memfail(char **splitted_s, size_t i)
{
	while (i > 0)
	{
		i--;
		free(splitted_s[i]);
	}
	free(splitted_s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_s;
	size_t	num_s;
	size_t	len_s;
	size_t	i;

	if (!s)
    	return (NULL);
	num_s = ft_splitcount(s, c);
	splitted_s = malloc(sizeof(char *) * (num_s + 1));
	if (splitted_s == NULL)
		return (NULL);
	i = 0;
	while (i < num_s)
	{
		while (*s && *s == c)
			s++;
		len_s = ft_splitlen(s, c);
		splitted_s[i] = malloc(len_s + 1);
		if (splitted_s[i] == NULL)
			return (ft_memfail(splitted_s, i));
		ft_memcpy(splitted_s[i], s, len_s);
		while (*s && *s != c)
			s++;
		splitted_s[i][len_s] = '\0';
		i++;
	}
	splitted_s[i] = NULL;
	return (splitted_s);
}

#include <stdio.h>

int	main(void)
{
	char	*s = "jedna dva tri ctyri";
	int		i;
	char	**splitted_s;

	splitted_s = ft_split(s, ' ');
	i = 0;
	while (i < 4)
	{
		printf("%s\n", splitted_s[i]);
		i++;
	}
	return (0);
}
