/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luflores <luflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:50:42 by luflores          #+#    #+#             */
/*   Updated: 2025/11/05 13:34:29 by luflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	size = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	size++;
	return (size);
}
