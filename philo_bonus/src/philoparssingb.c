/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoparssingb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:42 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/11 15:32:52 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philob.h"

int	ft_isdigit(int arg)
{
	if (arg == 0)
		return (0);
	if (arg >= 48 && arg <= 57)
	{
		return (1);
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		moins;
	long	res;

	i = 0;
	moins = 1;
	res = 0;
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins = -1 * moins;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res * moins > INT_MAX || res * moins < INT_MIN)
			exit(1);
	}
	return (res * moins);
}

int	checker(char **arg)
{
	int		j;
	int		k;

	j = 0;
	k = 1;
	while (arg[k])
	{
		if (arg[k][0] == '\0')
			return (0);
		j = 0;
		while (arg[k][j])
		{
			if (ft_isdigit(arg[k][j]) == 0)
				return (0);
			j++;
		}
		k++;
	}
	return (1);
}

void	remph(t_data *p, t_ph *ph)
{
	ph = rempdata(p->nbrphilo);
	ft_lstlast(&ph);
	mainnor(p);
	processwork(p, ph);
	if (p->nbrtoeat == -1)
	{
		waitpid(-1, &p->status, 0);
	}
	else
	{
		while (wait(&p->status) > 0)
		{
		}
	}
	killproc(p);
	detruirthread(p, ph);
	pthread_detach(p->ph->thphi);
}

void	detruirthread(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < p->nbrphilo)
	{
		pthread_detach(ph->thphi);
		ph = ph->next;
		i++;
	}
}
