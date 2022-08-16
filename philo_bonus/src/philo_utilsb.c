/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilsb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:28:49 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/11 17:31:09 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philob.h"

t_ph	*rempdata(int j)
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

void	*stopprob(void *ptr)
{
	t_data			*p;
	t_ph			*ph;

	p = (t_data *) ptr;
	ph = p->ph;
	while (p->fin)
	{
		if (((timeph() - p->starttime) - ph->last_to_eat) > p->tdie)
		{
			stopprobnor(p, ph);
		}
		if (ph->phnbrtoeat == p->nbrtoeat)
		{
			p->philofin++;
		}
		if (p->philofin == p->nbrphilo)
		{
			p->fin = 0;
			break ;
		}
	}
	return (0);
}

void	remplir(int ar, char **s, t_data *p)
{
	p->nbrphilo = ft_atoi(s[1]);
	p->tdie = ft_atoi(s[2]);
	p->teat = ft_atoi(s[3]);
	p->tsleep = ft_atoi(s[4]);
	p->nbrtoeat = -1;
	p->fin = 1;
	p->philofin = 0;
	if (ar == 6)
		p->nbrtoeat = ft_atoi(s[5]);
	if (p->nbrtoeat == 0)
		p->nbrtoeat = -1;
}

void	mainnor(t_data *p)
{
	p->fin = 1;
	p->philofin = -1;
	p->semname = "/semaphore";
	p->printabl = "/printable";
	p->semfin = "/semfin";
	sem_unlink(p->semname);
	sem_unlink(p->printabl);
	sem_unlink(p->semfin);
	p->sf = sem_open(p->semfin, O_CREAT | O_EXCL, 0644, p->nbrphilo);
	p->s = sem_open(p->semname, O_CREAT | O_EXCL, 0644, p->nbrphilo);
	p->pri = sem_open(p->printabl, O_CREAT | O_EXCL, 0644, 1);
	p->pid = (int *)malloc(p->nbrphilo * sizeof(int));
}

void	killproc(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->nbrphilo)
	{
		kill(p->pid[i], SIGKILL);
		i++;
	}
	sem_close(p->s);
	sem_close(p->pri);
	sem_close(p->sf);
	sem_unlink(p->printabl);
	sem_unlink(p->semname);
	sem_unlink(p->semfin);
	free(p->pid);
}
