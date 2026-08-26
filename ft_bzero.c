/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:51:18 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/08/25 15:05:14 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main(void)
// {
//     char str1[] = "Hello world!";
//     char str2[] = "Hello world!";

//     bzero(str1, 5);
//     ft_bzero(str2, 5);
//     printf("bzero: %s\n", str1);
// 	printf("ft_bzero: %s\n", str2);

//     int array1[5] = {1, 2, 3, 4, 5};
//     int array2[5] = {1, 2, 3, 4, 5};
// 	int		i;

//     bzero(array1, (3 * sizeof(int)));
//     ft_bzero(array2, 3 * sizeof(int));
// 	printf("bzero: ");
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d,", array1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("ft_bzero: ");
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d,", array2[i]);
// 		i++;
// 	}
// 	printf("\n");

//     return (0);
// }
