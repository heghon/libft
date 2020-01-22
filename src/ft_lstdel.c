/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:23:55 by bmenant           #+#    #+#             */
/*   Updated: 2018/11/26 12:54:05 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*chain;
	t_list	*next;

	chain = *alst;
	while (chain != NULL)
	{
		next = chain->next;
		del(chain->content, chain->content_size);
		free(chain);
		chain = next;
	}
	*alst = NULL;
}
