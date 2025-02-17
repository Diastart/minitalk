/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dias <dinursul@student.42.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:52:38 by Dias              #+#    #+#             */
/*   Updated: 2025/02/17 12:50:03 by Dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_transmit(pid_t server_pid, char c)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if (c & mask)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		mask >>= 1;
		usleep(750);
	}
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*str;

	if (ac != 3)
	{
		ft_printf("Usage: ./%s <server_pid> <string>\n", av[0]);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	str = av[2];
	while (*str)
		ft_transmit(server_pid, *str++);
	ft_transmit(server_pid, '\0');
	return (0);
}
