/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:34:39 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:30:27 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_flag;

void	change_flag(int signum)
{
	(void)signum;
	g_flag = 1;
}

void	send_char(pid_t pid, unsigned int c)
{
	unsigned int	mask;

	mask = 2147483648;
	while (mask > 0)
	{
		g_flag = 0;
		if (c & mask)
			kill(pid, ONE);
		else
			kill(pid, ZERO);
		mask >>= 1;
		while (!g_flag)
			usleep(100);
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	char	*str;

	if (ac != 3)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	signal(ONE, change_flag);
	pid = ft_atoi(av[1]);
	str = av[2];
	send_string(pid, str);
	write (1, "Message sent successfully!\n", 28);
	return (0);
}
