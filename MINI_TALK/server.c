/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:17 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/04 20:16:11 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_set_bit = 128;

static void	signal_handler(int signal_client)
{
	static int	bits = 0;
	static int	mess = 0;

	if (signal_client == SIGUSR1)
		mess |= g_set_bit;
	g_set_bit >>= 1;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", mess);
		bits = 0;
		mess = 0;
		g_set_bit = 128;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("The server PID: %d\n", server_pid);
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
