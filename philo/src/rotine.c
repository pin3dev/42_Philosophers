/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:19 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:10:21 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish_flag(t_philo *philo, int check_or_command)
{
	pthread_mutex_lock(&philo->table->mtx_finish);
	if (check_or_command == ORDER || philo->table->finish_flag == TRUE)
	{
		if (check_or_command == ORDER)
			philo->table->finish_flag = TRUE;
		pthread_mutex_unlock(&philo->table->mtx_finish);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->table->mtx_finish);
	return (FALSE);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->mtx_forks[philo->left_fork]);
		pthread_mutex_lock(&philo->table->mtx_forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->mtx_forks[philo->right_fork]);
		pthread_mutex_lock(&philo->table->mtx_forks[philo->left_fork]);
	}
	print(philo, "has taken a fork");
	print(philo, "has taken a fork");
}

void	eat_n_sleep(t_philo *philo)
{
	take_forks(philo);
	print(philo, "is eating");
	doing(philo, philo->table->arg_eat);
	pthread_mutex_lock(&philo->table->mtx_eat);
	philo->food_refill++;
	philo->last_meal = get_now();
	pthread_mutex_unlock(&philo->table->mtx_eat);
	pthread_mutex_unlock(&philo->table->mtx_forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->table->mtx_forks[philo->left_fork]);
	print(philo, "is sleeping");
	doing(philo, philo->table->arg_sleep);
}

void	*dinner(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->table->arg_philos == 1)
	{
		print(philo, "has taken a fork");
		doing(philo, philo->table->arg_die);
		print(philo, "died");
		check_finish_flag(philo, ORDER);
		return (KO);
	}
	if (philo->id % 2 == 0)
		usleep(philo->table->arg_eat * 1000);
	while (OK)
	{
		if (check_finish_flag(philo, CHECK))
			return (KO);
		eat_n_sleep(philo);
		print(philo, "is thinking");
		if (philo->table->arg_philos % 2 != 0)
			doing(philo, philo->table->arg_eat);
	}
	return (KO);
}
