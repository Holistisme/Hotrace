/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luflores <luflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:49:22 by luflores          #+#    #+#             */
/*   Updated: 2025/11/05 13:34:27 by luflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nwnode;

	nwnode = (t_list *)malloc(sizeof(struct s_list *) + 8);
	if (!nwnode)
		return (NULL);
	nwnode->content = content;
	nwnode->next = NULL;
	return (nwnode);
}
