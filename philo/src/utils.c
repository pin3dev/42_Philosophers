/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:09:58 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:38:18 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	doing(t_philo *philo, long long stop)
{
	long long	run_time;

	run_time = get_now();
	while (check_finish_flag(philo, CHECK) == \
		FALSE && (get_now() - run_time) < stop)
		usleep(100);
}

void	print(t_philo *philo, const char *status)
{
	long long	time;

	pthread_mutex_lock(&philo->table->mtx_print);
	if (check_finish_flag(philo, CHECK) == FALSE)
	{
		time = get_now() - philo->table->init_time;
		printf("%lld %d %s\n", time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->mtx_print);
}

long long	get_now(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

int	s_atoi(const char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (str[0] == '-')
		print_error_n_exit("Only positive numbers", NULL, 0);
	while (str[++i])
		res = res * 10 + (str[i] - 48);
	if (res > 2147483647)
		print_error_n_exit("Args must fit in an INT", NULL, 0);
	return (res);
}
