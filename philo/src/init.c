/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:29:10 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:38:46 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner_reception(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->arg_philos)
	{
		if (pthread_create(&table->philo[i].thread, NULL, \
			dinner, &table->philo[i]))
			print_error_n_exit("Philos can't start dinner, \
				Thread Error", table, ERR_ALL);
	}
	return (0);
}

void	mtxs(t_table *table)
{
	int	i;

	i = -1;
	table->mtx_forks = malloc(sizeof(pthread_mutex_t) * table->arg_philos);
	if (!table->mtx_forks)
		print_error_n_exit("Forks not available, \
			Malloc Error", table, ERR_MALLOC);
	while (++i < table->arg_philos)
	{
		if (pthread_mutex_init(&table->mtx_forks[i], NULL))
			print_error_n_exit("Forks not available, \
				Init Error", table, ERR_MUTEX_MALLOC);
	}
	if (pthread_mutex_init(&table->mtx_print, NULL))
		print_error_n_exit("Print check key not available, \
			Init Error", table, ERR_MUTEX_MALLOC);
	if (pthread_mutex_init(&table->mtx_eat, NULL))
		print_error_n_exit("Meals check key not available, \
			Init Error", table, ERR_MUTEX_MALLOC);
	if (pthread_mutex_init(&table->mtx_finish, NULL))
		print_error_n_exit("Finish check key not available, \
			Init Error", table, ERR_MUTEX_MALLOC);
}

void	invite_philos(t_table *table)
{
	int	i;

	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->arg_philos);
	if (!table->philo)
		print_error_n_exit("Philos not invited, \
			Malloc Error", table, ERR_MALLOC);
	table->init_time = get_now();
	while (++i < table->arg_philos)
	{
		table->philo[i].id = i + 1;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->arg_philos;
		table->philo[i].food_refill = 0;
		table->philo[i].last_meal = table->init_time;
		table->philo[i].table = table;
	}
}
