/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 16:16:10 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/27 16:33:07 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;
	
	total_size = count * size;
	if (count > 0 && size > 0 && total_size / count != size)
    	return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, total_size);
	return (ptr);	
}

#include <stdio.h>

int	main(void)
{
	const char	*str = "-12345";

	printf("%d", ft_atoi(str));

	return (0);
}