/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:26:27 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 00:54:26 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	g_msg.byte <<= 1;
	if (signum == ONE)
		g_msg.byte |= 1;
	else
		g_msg.byte |= 0;
	g_msg.counter++;
	if (g_msg.counter == 8)
	{
		if (g_msg.byte == 0)
			write (1, "\n", 1);
		else
			write (1, &g_msg.byte, 1);
		g_msg.byte = 0;
		g_msg.counter = 0;
	}
	kill(pid, ONE);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	write (1, "PID: ", 5);
	ft_putnbr(pid);
	write (1, "\n", 1);
	g_msg.byte = 0;
	g_msg.counter = 0;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(ONE, &sa, NULL);
	sigaction(ZERO, &sa, NULL);
	while (1)
		pause();
	return (0);
}
