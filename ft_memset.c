/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:46:31 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/25 14:59:35 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
		
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (s);
}

// int main(void)
// {
//     char str1[] = "Hello world!";
//     char str2[] = "Hello world!";

//     memset(str1, 'X', 5);
//     ft_memset(str2, 'X', 5);
//     printf("memset: %s\n", str1);
// 	printf("ft_memset: %s\n", str2);

//     int array1[5] = {1, 2, 3, 4, 5};
//     int array2[5] = {1, 2, 3, 4, 5};
// 	int		i;

//     memset(array1, 0, (3 * sizeof(int)));
//     ft_memset(array2, 0, 3 * sizeof(int));
// 	printf("memset: ");
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d,", array1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("ft_memset: ");
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d,", array2[i]);
// 		i++;
// 	}
// 	printf("\n");

//     return (0);
// }
