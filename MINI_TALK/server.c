/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:34:17 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/03 10:52:16 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handle1(){
	printf("SIG ACTION 1\n");
}

void sig_handle2(){
	printf("SIG ACTION 2\n");
}

void signal_h()
{

}

int main()
{
	pid_t server_pid = getpid();

	printf("The server PID: %d\n", server_pid);
	signal(SIGUSR1, &sig_handle1);
	signal(SIGUSR2, &sig_handle2);
	while (1)
		pause();
	return EXIT_SUCCESS;
}
