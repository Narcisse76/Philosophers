/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trambure <trambure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:55:43 by narcisse          #+#    #+#             */
/*   Updated: 2025/10/26 21:19:35 by trambure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <time.h>

static void	write_status_debug(t_philo_status status, t_philo *philo,
	long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("%6ld" " %d has taken the 1° fork" "\t\t\tn°[%d]\n", elapsed,
			philo->id, philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%6ld" " %d has taken the 2° fork" "\t\t\tn°[%d]\n", elapsed,
			philo->id, philo->first_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%6ld %d is eating\t\t\t [%ld]\n", elapsed, philo->id,
			philo->last_meal);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld"" %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld"" %d is thinking\n", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("%-6ld"" %d died\n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_time;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->table))
			printf("%-6ld"" %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf("%-6ld"" %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf("%-6ld"" %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf("%-6ld"" %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf("%-6ld"" %d died\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
