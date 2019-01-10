/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:20:24 by bmenant           #+#    #+#             */
/*   Updated: 2018/11/26 13:51:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_bis;
	t_list	*beg_lst_bis;
	t_list	*temp;

	if (lst)
	{
		temp = f(lst);
		if (!(lst_bis = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		lst = lst->next;
		beg_lst_bis = lst_bis;
		while (lst != NULL)
		{
			temp = f(lst);
			if (!(lst_bis->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			lst = lst->next;
			lst_bis = lst_bis->next;
		}
		return (beg_lst_bis);
	}
	return (NULL);
}
