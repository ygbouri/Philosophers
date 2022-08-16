/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoparssing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:42 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/10 17:44:25 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigitm(int arg)
{
	if (arg == 0)
		return (0);
	if (arg >= 48 && arg <= 57)
	{
		return (1);
	}
	return (0);
}

long	ft_atoim(const char *str)
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

void	mainnorm(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	p->fin = 1;
	ft_lstlast(&ph);
	initmutex(p, ph);
	p->ph = ph;
	p->ph->checker = 0;
	lanceth(p, ph);
}

int	checkerm(char **arg)
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
			if (ft_isdigitm(arg[k][j]) == 0)
				return (0);
			j++;
		}
		k++;
	}
	return (1);
}

void	destroymutex(t_data *p, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < p->nbrphilo)
	{
		pthread_mutex_destroy(&ph->fork);
		ph = ph->next;
		i++;
	}
}
