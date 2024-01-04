/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:21 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/03 15:26:34 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int server_pid, char *message)
{
	
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		write(2, "\033[1;31mUsage: ", 14);
		write(2, "\033[0m./client <server_pid> <message>\n", 36);
		exit (EXIT_FAILURE);
	}
	server_pid = atoi(av[1]);
	if (server_pid <= 0)
	{
		write(2, "\033[1;31mError: \033[0mInvalid server PID.\n\033[0;33m", 45);
		write(2, "-> Please provide a valid PID greater than 0.\n", 46);
		exit (EXIT_FAILURE);
	}
	signal_handler(server_pid, av[2]);
	return (EXIT_SUCCESS);
}
