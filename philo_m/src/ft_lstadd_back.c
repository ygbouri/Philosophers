/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 05:08:16 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/03 17:17:42 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	ft_lstadd_back(t_ph **alst, t_ph *new)
{
	t_ph	*p;

	p = NULL;
	if (alst)
	{
		if ((*alst) == NULL)
			(*alst) = new;
		else
		{
			p = *alst;
			while (p->next != NULL)
				p = p->next;
			p->next = new;
		}
	}
}
