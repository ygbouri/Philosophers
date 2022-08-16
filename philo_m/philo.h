/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:56 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/09 21:19:01 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

int		ft_isdigitm(int arg);
long	ft_atoim(const char *str);
int		checkerm(char **arg);
typedef struct s_ph
{
	int					id;
	int					last_to_eat;
	int					phnbrtoeat;
	int					checker;
	pthread_mutex_t		fork;
	pthread_t			thphi;
	struct s_ph			*next;
	struct s_data		*p;
}				t_ph;

typedef struct s_data
{
	int				nbrphilo;
	int				teat;
	int				tsleep;
	int				tdie;
	int				nbrtoeat;
	int				fin;
	int				philofin;
	int				starttime;
	pthread_mutex_t	pri;
	t_ph			*ph;
}					t_data;
int		timeph(void);
t_ph	*rempdatam(int j);
t_ph	*ft_lstnew(int idp);
void	mainnorm(t_data *p, t_ph *ph);
void	ft_lstadd_back(t_ph **alst, t_ph *new);
void	ft_lstlast(t_ph	**lst);
void	lanceth(t_data *p, t_ph *ph);
void	initmutex(t_data *p, t_ph *ph);
void	destroymutex(t_data *p, t_ph *ph);
void	stopprom(t_data *p);
void	remplirm(int ar, char **s, t_data *p);

#endif