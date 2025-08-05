/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:28:44 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:36:09 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_or_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mtx_eat);
	if (get_now() - philo->last_meal >= philo->table->arg_die)
	{
		print(philo, "died");
		check_finish_flag(philo, ORDER);
		pthread_mutex_unlock(&philo->table->mtx_eat);
		return (TRUE);
	}
	else if (philo->table->arg_meals > 0
		&& philo->food_refill >= philo->table->arg_meals)
	{
		philo->table->full_philos++;
		if (philo->table->full_philos >= philo->table->arg_philos)
		{
			check_finish_flag(philo, ORDER);
			pthread_mutex_lock(&philo->table->mtx_print);
			printf("All philosophers ate enough!\n");
			pthread_mutex_unlock(&philo->table->mtx_print);
			pthread_mutex_unlock(&philo->table->mtx_eat);
			return (TRUE);
		}
	}
	pthread_mutex_unlock(&philo->table->mtx_eat);
	return (FALSE);
}

void	waiter_the_monitor(t_table *table)
{
	int	i;
	int	go;

	go = TRUE;
	while (go)
	{
		i = -1;
		table->full_philos = 0;
		while (++i < table->arg_philos)
		{
			if (go && check_dead_or_full(&table->philo[i]))
				go = FALSE;
		}
		usleep(10);
	}
	exit_threads(table);
}
