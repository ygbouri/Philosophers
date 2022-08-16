/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:25:49 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/11 17:31:18 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philob.h"

void	stopprobnor(t_data *p, t_ph *ph)
{
	if (p->ph->checker == 0)
	{
		p->fin = 0;
		sem_wait(p->pri);
		printf("%d %d died\n", (timeph() - p->starttime), ph->id);
		exit(0);
	}
}

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
