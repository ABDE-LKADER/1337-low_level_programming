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

void signal_handler(int client_signal)
{
	
}

int main()
{
	pid_t server_pid = getpid();

	printf("The server PID: %d\n", server_pid);
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
		pause();
	return EXIT_SUCCESS;
}
