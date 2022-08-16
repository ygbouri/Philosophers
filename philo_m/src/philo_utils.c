/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:28:49 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/10 17:51:49 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_ph	*rempdatam(int j)
{
	t_ph	*p;
	t_ph	*nd;
	int		i;

	i = 2;
	p = ft_lstnew(1);
	while (i <= j)
	{
		nd = ft_lstnew(i);
		ft_lstadd_back(&p, nd);
		i++;
	}
	return (p);
}

void	initmutex(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < p->nbrphilo)
	{
		pthread_mutex_init(&ph->fork, NULL);
		ph = ph->next;
		ph->p = p;
		i++;
	}
}

void	stopprom(t_data *p)
{
	t_ph	*ph;

	ph = p->ph;
	while (1)
	{
		if (((timeph() - p->starttime) - ph->last_to_eat) > p->tdie)
		{
			if (ph->checker != 1)
			{
				p->fin = 0;
				pthread_mutex_lock(&p->pri);
				printf("%d %d died\n", (timeph() - p->starttime), ph->id);
				pthread_mutex_destroy(&p->pri);
				break ;
			}
		}
		else if (p->philofin == p->nbrphilo)
		{
			p->fin = 0;
			break ;
		}
		ph = ph->next;
	}
}

void	remplirm(int ar, char **s, t_data *p)
{
	p->nbrphilo = ft_atoim(s[1]);
	p->tdie = ft_atoim(s[2]);
	p->teat = ft_atoim(s[3]);
	p->tsleep = ft_atoim(s[4]);
	p->nbrtoeat = -1;
	p->fin = 1;
	p->philofin = 0;
	if (ar == 6)
		p->nbrtoeat = ft_atoim(s[5]);
	if (p->nbrtoeat == 0)
		p->nbrtoeat = -1;
}
