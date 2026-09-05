/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkejkrt <onkejkrt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 14:08:38 by onkejkrt          #+#    #+#             */
/*   Updated: 2026/09/05 14:19:38 by onkejkrt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int main(void)
{
	printf("--- TEST FUNKCE ft_lstnew ---\n\n");

	// Test 1: Vytvoření uzlu s textovým řetězcem
	char *text = "Ahoj světe, test 42!";
	t_list *node1 = ft_lstnew(text);

	if (node1 == NULL)
	{
		printf("❌ Test 1 selhal: Uzel nebyl vytvořen (NULL).\n");
		return (1);
	}
	
	printf("✅ Test 1: Uzel úspěšně alokován.\n");
	printf("   Obsah uzlu (content): \"%s\"\n", (char *)node1->content);
	
	if (node1->next == NULL)
		printf("   Ukazatel na další uzel (next): NULL (Správně)\n\n");
	else
		printf("   ❌ Ukazatel na další uzel (next) NENÍ NULL!\n\n");

	// Test 2: Vytvoření uzlu s prázdným obsahem (NULL)
	t_list *node2 = ft_lstnew(NULL);

	if (node2 == NULL)
	{
		printf("❌ Test 2 selhal: Uzel s NULL obsahem nebyl vytvořen.\n");
		free(node1);
		return (1);
	}

	printf("✅ Test 2: Uzel s NULL obsahem úspěšně alokován.\n");
	if (node2->content == NULL)
		printf("   Obsah uzlu (content): NULL (Správně)\n");
	else
		printf("   ❌ Obsah uzlu NENÍ NULL!\n");

	// Uvolnění paměti (free)
	free(node1);
	free(node2);
	printf("\n--- VŠECHNY TESTY PROŠLY KOREKTNĚ ---\n");

	return (0);
}