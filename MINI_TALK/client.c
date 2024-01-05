/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:21 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/04 20:26:44 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int server_pid, unsigned char mes)
{
	int	num_bit;
	int	check_bits = 128;

	num_bit = 8;
	while (num_bit--)
	{	
		if (mes & check_bits)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		check_bits >>= 1;
		usleep(WAIT_TIME);
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		write(2, "\033[1;31mUsage: ", 14);
		write(2, "\033[0m./client <server_pid> <message>\n", 36);
		return (EXIT_FAILURE);
	}
	server_pid = atoi(av[1]);
	if (server_pid <= 0)
	{
		write(2, "\033[1;31mError: \033[0mInvalid server PID.\n\033[0;33m", 45);
		write(2, "-> Please provide a valid PID greater than 0.\n", 46);
		return (EXIT_FAILURE);
	}
	while (*av[2])
		signal_handler(server_pid, *av[2]++);
	signal_handler(server_pid, '\0');
	signal_handler(server_pid, '\n');
	return (EXIT_SUCCESS);
}
