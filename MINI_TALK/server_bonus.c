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

#include "minitalk_bonus.h"

int	g_set_bit = 128;

void	signal_handler(int signal_client, siginfo_t *sig_inf, void *none)
{
	static int	bits = 0;
	static int	mess = 0;

	(void)none;
	if (signal_client == SIGUSR1)
		mess |= g_set_bit;
	g_set_bit >>= 1;
	bits++;
	if (bits == 8)
	{
		if (!mess)
			kill(sig_inf->si_pid, SIGUSR1);
		printf("%c", mess);
		bits = 0;
		mess = 0;
		g_set_bit = 128;
	}
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	set_sig;

	server_pid = getpid();
    set_sig.sa_sigaction = signal_handler;
	set_sig.sa_flags = SA_SIGINFO;
	sigemptyset(&set_sig.sa_mask);
	sigaddset(&set_sig.sa_mask, SIGUSR1);
	sigaddset(&set_sig.sa_mask, SIGUSR2);
	printf("The server PID: %d\n", server_pid);
	sigaction(SIGUSR1, &set_sig, NULL);
	sigaction(SIGUSR2, &set_sig, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
