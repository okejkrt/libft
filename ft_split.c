/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:04:57 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/08 11:28:49 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitcount(char const *s, char c)
{
	size_t	s_count;
	size_t	i;

	s_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			s_count++;
		i++;
	}
	return (s_count);
}

static char	**ft_memfail(char **s_split, size_t i)
{
	while (i > 0)
	{
		i--;
		free(s_split[i]);
	}
	free(s_split);
	return (NULL);
}

static char	**ft_splitcpy(char const *s, char c, char **s_split, size_t s_count)
{
	size_t		i;
	char const	*s_start;

	i = 0;
	while (i < s_count)
	{
		while (*s && *s == c)
			s++;
		s_start = s;
		while (*s && *s != c)
			s++;
		s_split[i] = ft_substr(s_start, 0, (size_t)(s - s_start));
		if (s_split[i] == NULL)
			return (ft_memfail(s_split, i));
		i++;
	}
	s_split[i] = NULL;
	return (s_split);
}

char	**ft_split(char const *s, char c)
{
	char		**s_split;
	size_t		s_count;

	if (!s)
		return (NULL);
	s_count = ft_splitcount(s, c);
	s_split = malloc(sizeof(char *) * (s_count + 1));
	if (s_split == NULL)
		return (NULL);
	return (ft_splitcpy(s, c, s_split, s_count));
}
