/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:34:43 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:32:22 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_msg	g_msg;

void	write_unicode(unsigned int c)
{
	unsigned char	bytes[1];

	if (c < 128)
	{
		bytes[0] = c;
		write(1, bytes, 1);
	}
	else if (c < 2048)
		write_utf8_2bytes(c);
	else if (c < 65536)
		write_utf8_3bytes(c);
	else
		write_utf8_4bytes(c);
}

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
	if (g_msg.counter == 32)
	{
		if (g_msg.byte == 0)
			write (1, "\n", 1);
		else
			write_unicode(g_msg.byte);
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
