/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luflores <luflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:01:25 by luflores          #+#    #+#             */
/*   Updated: 2025/11/05 13:34:22 by luflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*result;
	t_list			*new;
	void			*temp;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			del(temp);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
