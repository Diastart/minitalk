/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dias <dinursul@student.42.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:15:36 by Dias              #+#    #+#             */
/*   Updated: 2025/02/17 12:52:44 by Dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server_mandatory	g_server;

void	ft_sighandler(int signum)
{
	g_server.letter <<= 1;
	if (signum == SIGUSR1)
		g_server.letter |= 1;
	g_server.counter++;
	if (g_server.counter == 8)
	{
		if (g_server.letter == 0)
			ft_printf("\n");
		else
			ft_printf("%c", g_server.letter);
		g_server.letter = 0;
		g_server.counter = 0;
	}
}

int	ft_setup(void)
{
	struct sigaction	sa;

	g_server.letter = 0;
	g_server.counter = 0;
	sa.sa_handler = &ft_sighandler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == 1 \
	|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(void)
{
	if (!ft_setup())
	{
		ft_printf("Error: could not set up signal handlers\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
