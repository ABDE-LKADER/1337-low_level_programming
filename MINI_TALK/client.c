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
	int nbit;

	nbit = 8;
	while (nbit--)
	{	
		if (mes % 2 == 0)
		{
			kill();
		}
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
	return (EXIT_SUCCESS);
}




void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}