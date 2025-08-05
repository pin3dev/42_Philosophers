/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:10:13 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:35:36 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_n_free_malloc(t_table *table)
{
	free (table->philo);
	free (table->mtx_forks);
}

void	exit_mtxs(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->arg_philos)
		pthread_mutex_destroy(&table->mtx_forks[i]);
	exit_n_free_malloc(table);
	pthread_mutex_destroy(&table->mtx_print);
	pthread_mutex_destroy(&table->mtx_eat);
	pthread_mutex_destroy(&table->mtx_finish);
}

void	exit_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->arg_philos)
		pthread_join(table->philo[i].thread, NULL);
	exit_mtxs(table);
}

void	print_error_n_exit(char *msg, t_table *table, int n)
{
	printf("Error: %s\n", msg);
	if (n == ERR_MALLOC)
		exit_n_free_malloc(table);
	if (n == ERR_MUTEX_MALLOC)
		exit_mtxs(table);
	if (n == ERR_ALL)
		exit_threads(table);
	exit(1);
}
