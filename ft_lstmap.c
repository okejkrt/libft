/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:41:44 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/05 16:31:43 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_lst = malloc(sizeof(t_list));
		new_lst.content = lst.content;
		new_lst.next st;
		lst = lst->lst.next
		temp = new_l;
	}
	
}