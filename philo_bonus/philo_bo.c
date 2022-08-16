/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:19:41 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/15 17:29:56 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philob.h"

void	routinecontinue(t_data *p, t_ph *ph)
{
	p->ph->checker = 1;
	ph->last_to_eat = (timeph() - p->starttime);
	usleep(p->teat * 1000);
	p->ph->checker = 0;
	if (p->nbrtoeat != -1)
	{
		ph->phnbrtoeat++;
		p->ph = ph;
	}
	sem_post(p->s);
	sem_post(p->s);
	sem_wait(p->pri);
	printf("%d %d sleeping\n", ((timeph() - p->starttime)), ph->id);
	sem_post(p->pri);
	usleep(p->tsleep * 1000);
	sem_wait(p->pri);
	printf("%d %d thinking\n", ((timeph() - p->starttime)), ph->id);
	sem_post(p->pri);
}

void	*routine(t_data *p, t_ph *ph)
{
	pthread_create(&(ph->thphi), 0, &stopprob, p);
	if (ph->id % 2 == 0)
		usleep(100);
	while (p->fin)
	{
		sem_wait(p->s);
		sem_wait(p->pri);
		printf("%d %d has taken a fork\n", (timeph() - p->starttime), ph->id);
		sem_post(p->pri);
		sem_wait(p->s);
		sem_wait(p->pri);
		printf("%d %d has taken next fork\n", (timeph() - p->starttime), ph->id);
		sem_post(p->pri);
		sem_wait(p->pri);
		printf("%d %d eating\n", ((timeph() - p->starttime)), ph->id);
		sem_post(p->pri);
		routinecontinue(p, ph);
	}
	return (0);
}

int	timeph(void)
{
	struct timeval	current_time;
	int				tenmilli;

	gettimeofday(&current_time, 0);
	tenmilli = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (tenmilli);
}

void	processwork(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	p->starttime = timeph();
	while (i < p->nbrphilo)
	{
		ph->checker = 0;
		p->ph = ph;
		p->pid[i] = fork();
		if (p->pid[i] == 0)
		{
			routine(p, ph);
			exit(0);
		}
		i++;
		ph = ph->next;
	}
}

int	main(int ar, char **arg)
{
	t_data		p;
	t_ph		*ph;

	ph = NULL;
	if (ar == 5 || ar == 6)
	{
		if (checker(arg) == 0)
		{
			printf("Error sould be enter a number\n");
			return (1);
		}
		remplir(ar, arg, &p);
		if (p.nbrphilo <= 0 || p.tdie < 60 || p.teat < 60 || p.tsleep < 60)
			return (0);
		if (p.nbrphilo > 200)
		{
			printf("number of philosophers is big max 200\n");
			return (0);
		}		
		remph(&p, ph);
	}
	else
		printf("more arguments\n");
	return (0);
}
