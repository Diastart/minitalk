/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:34:47 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:39:15 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# define ONE 30
# define ZERO 31

typedef struct s_msg
{
	unsigned int	byte;
	int				counter;
}				t_msg;

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	send_string(pid_t pid, char *str);
void	send_utf8_2bytes(pid_t pid, unsigned char byte, char *str, int *i);
void	send_utf8_3bytes(pid_t pid, unsigned char byte, char *str, int *i);
void	send_utf8_4bytes(pid_t pid, unsigned char byte, char *str, int *i);
void	write_utf8_2bytes(unsigned int c);
void	write_utf8_3bytes(unsigned int c);
void	write_utf8_4bytes(unsigned int c);
void	send_char(pid_t pid, unsigned int c);

#endif