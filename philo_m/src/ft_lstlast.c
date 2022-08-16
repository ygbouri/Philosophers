/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:25:49 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/03 17:17:54 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	ft_lstlast(t_ph	**lst)
{
	t_ph	*p;

	if (lst)
	{
		p = *lst;
		while (p->next != NULL)
			p = p->next;
		p->next = (*lst);
	}
}
