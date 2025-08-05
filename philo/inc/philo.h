/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:51:56 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 19:52:09 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				food_refill;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	struct s_table	*table;
	pthread_t		thread;
}					t_philo;

typedef struct s_table
{
	int				arg_philos;
	int				arg_die;
	int				arg_eat;
	int				arg_sleep;
	int				arg_meals;
	int				full_philos;
	int				finish_flag;
	long long		init_time;
	t_philo			*philo;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_eat;
	pthread_mutex_t	mtx_finish;
}					t_table;

# define TRUE 1
# define FALSE 0
# define KO 0
# define OK 1
# define ERR_MALLOC 1
# define ERR_MUTEX_MALLOC 2
# define ERR_ALL 3
# define CHECK 0
# define ORDER 1

void		doing(t_philo *philo, long long ms);
void		print(t_philo *philo, const char *status);
long long	get_now(void);
void		print_error_n_exit(char *msg, t_table *table, int n);
int			s_atoi(const char *s);

void		mtxs(t_table *table);
void		invite_philos(t_table *table);
void		mise_en_place(t_table *table, int ac, char **av);

int			check_finish_flag(t_philo *philo, int order);
int			check_dead_or_full(t_philo *philo);
void		eat_n_sleep(t_philo *philo);
void		*dinner(void *arg);
int			dinner_reception(t_table *table);

void		exit_n_free_malloc(t_table *table);
void		exit_mtxs(t_table *table);
void		exit_threads(t_table *table);
void		waiter_the_monitor(t_table *table);

#endif
