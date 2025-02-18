/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:16:41 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:19:32 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# define ONE 30
# define ZERO 31

typedef struct s_msg
{
	char	byte;
	int		counter;
}				t_msg;

int		ft_atoi(const char *str);
void	ft_putnbr(int n);

#endif