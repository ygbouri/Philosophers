/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philob.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:25:56 by ygbouri           #+#    #+#             */
/*   Updated: 2022/08/11 17:31:30 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOB_H
# define PHILOB_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

int		ft_isdigit(int arg);
long	ft_atoi(const char *str);
int		checker(char **arg);
typedef struct s_ph
{
	int					id;
	int					last_to_eat;
	int					phnbrtoeat;
	int					checker;
	pthread_t			thphi;
	struct s_ph			*next;
	struct s_data		*p;
}				t_ph;

typedef struct s_data
{
	int				latime;
	int				nbrphilo;
	int				teat;
	int				tsleep;
	int				tdie;
	int				nbrtoeat;
	int				fin;
	int				philofin;
	int				starttime;
	int				*pid;
	int				status;
	char			*semname;
	char			*printabl;
	char			*semfin;
	sem_t			*sf;
	sem_t			*s;
	sem_t			*pri;
	sem_t			*finish;
	t_ph			*ph;
}					t_data;
int		timeph(void);
t_ph	*rempdata(int j);
t_ph	*ft_lstnew(int idp);
void	ft_lstadd_back(t_ph **alst, t_ph *new);
void	ft_lstlast(t_ph	**lst);
void	remph(t_data *p, t_ph *ph);
void	mainnor(t_data *p);
void	processwork(t_data *p, t_ph *ph);
void	detruirthread(t_data *p, t_ph *ph);
void	killproc(t_data *p);
void	stopprobnor(t_data *p, t_ph *ph);
void	*stopprob(void *ptr);
void	remplir(int ar, char **s, t_data *p);

#endif