/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:09:50 by ivbatist          #+#    #+#             */
/*   Updated: 2023/07/31 20:09:51 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mise_en_place(t_table *table, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		print_error_n_exit("Wrong Input", NULL, 0);
	table->arg_philos = s_atoi(av[1]);
	table->arg_die = s_atoi(av[2]);
	table->arg_eat = s_atoi(av[3]);
	table->arg_sleep = s_atoi(av[4]);
	table->finish_flag = FALSE;
	table->arg_meals = -1;
	if (ac == 6)
		table->arg_meals = s_atoi(av[5]);
	if (table->arg_philos < 1 || table->arg_die < 60
		|| table->arg_eat < 60 || table->arg_sleep < 60
		|| (ac == 6 && table->arg_meals < 1))
		print_error_n_exit("Invalid values", NULL, 0);
}

int	main(int ac, char **av)
{
	t_table	table;

	mise_en_place(&table, ac, av);
	invite_philos(&table);
	mtxs(&table);
	dinner_reception(&table);
	waiter_the_monitor(&table);
}
