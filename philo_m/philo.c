/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:19:41 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/11 19:15:25 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timeph(void)
{
	struct timeval	current_time;
	int				tenmilli;

	gettimeofday(&current_time, NULL);
	tenmilli = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (tenmilli);
}

void	routinecontinue(t_data *p, t_ph *ph)
{
	if (p->nbrtoeat != -1)
	{
		ph->phnbrtoeat++;
		if (ph->phnbrtoeat == p->nbrtoeat)
			p->philofin++;
	}
	p->ph->checker = 1;
	ph->last_to_eat = (timeph() - p->starttime);
	usleep(p->teat * 1000);
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&ph->next->fork);
	p->ph->checker = 0;
	pthread_mutex_lock(&p->pri);
	printf("%d %d sleeping\n", ((timeph() - p->starttime)), ph->id);
	pthread_mutex_unlock(&p->pri);
	usleep(p->tsleep * 1000);
	pthread_mutex_lock(&p->pri);
	printf("%d %d thinking\n", ((timeph() - p->starttime)), ph->id);
	pthread_mutex_unlock(&p->pri);
}

void	*routine(void *ptr)
{	
	t_data			*p;
	t_ph			*ph;

	ph = (t_ph *) ptr;
	p = ph->p;
	pthread_mutex_init(&p->pri, NULL);
	if (ph->id % 2 == 0)
		usleep (100);
	while (p->fin)
	{
		pthread_mutex_lock(&ph->fork);
		pthread_mutex_lock(&p->pri);
		printf("%d %d has taken a fork\n", (timeph() - p->starttime), ph->id);
		pthread_mutex_unlock(&p->pri);
		pthread_mutex_lock(&ph->next->fork);
		pthread_mutex_lock(&p->pri);
		printf("%d %d has taken next fork\n", (timeph() - p->starttime), ph->id);
		pthread_mutex_unlock(&p->pri);
		pthread_mutex_lock(&p->pri);
		printf("%d %d eating\n", ((timeph() - p->starttime)), ph->id);
		pthread_mutex_unlock(&p->pri);
		routinecontinue(p, ph);
	}
	return (0);
}

void	lanceth(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < p->nbrphilo)
	{
		p->starttime = timeph();
		pthread_create(&p->ph->thphi, NULL, &routine, p->ph);
		p->ph = p->ph->next;
		i++;
	}
	stopprom(p);
	i = 0;
	while (i < p->nbrphilo)
	{
		pthread_detach(p->ph->thphi);
		p->ph = p->ph->next;
		i++;
	}
	destroymutex(p, ph);
	pthread_mutex_destroy(&p->pri);
}

int	main(int ar, char **arg)
{
	t_data		p;
	t_ph		*ph;

	if (ar == 5 || ar == 6)
	{
		if (checkerm(arg) == 0)
		{
			printf("Error sould be enter a number\n");
			return (0);
		}
		remplirm(ar, arg, &p);
		if (p.nbrphilo <= 0 || p.tdie < 60 || p.teat < 60 || p.tsleep < 60)
			return (printf("arguments invalid\n"), 0);
		if (p.nbrphilo > 200)
			return (printf("number of philosophers is big\nmax 200\n"), 0);
		ph = rempdatam(p.nbrphilo);
		mainnorm(&p, ph);
	}
	else
		printf("more arguments\n");
	return (0);
}
