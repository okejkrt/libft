/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:01:55 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/26 11:36:57 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	
	if (dest == NULL && src == NULL)
    	return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	while (n > 0)
	{
		*ptr_dest++ = *ptr_src++;
		n--;
	}
	return (dest);
}

int main(void)
{
    char str1[13] = "Hello world!";
    char str2[6];

    ft_memcpy(str2, str1, 5);
    printf("Original: %s\n", str1);
	printf("Copy: %s\n", str2);

    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5];
	int		i;

    ft_memcpy(array2, array1, 3 * sizeof(int));
	printf("Original: ");
	i = 0;
	while (i < 5)
	{
		printf("%d,", array1[i]);
		i++;
	}
	printf("\n");
	printf("Copy: ");
	i = 0;
	while (i < 5)
	{
		printf("%d,", array2[i]);
		i++;
	}
	printf("\n");

    return (0);
}
