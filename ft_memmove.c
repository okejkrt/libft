/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:33:10 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/26 11:21:13 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
    	return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	}
	return (dest);
}

int main(void)
{
    char str1[13] = "abcdefghij";

    ft_memmove(&str1[1], &str1[0], 5);
    printf("Original: %s\n", str1);
	printf("Copy: %s\n", &str1[1]);

    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5];
	int		i;

    ft_memmove(array2, array1, 3 * sizeof(int));
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
