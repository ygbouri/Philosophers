/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 06:56:44 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/03 18:32:14 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philob.h"

t_ph	*ft_lstnew(int idp)
{
	t_ph	*element;

	element = (t_ph *)malloc(sizeof(t_ph));
	if (!element)
		return (NULL);
	element->id = idp;
	element->last_to_eat = 0;
	element->phnbrtoeat = 0;
	element->next = NULL;
	return (element);
}
