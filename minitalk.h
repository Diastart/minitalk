/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dias <dinursul@student.42.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:34:47 by Dias              #+#    #+#             */
/*   Updated: 2025/02/17 12:49:29 by Dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define MAX_ATTEMPTS 5

typedef struct s_server_mandatory
{
	char	letter;
	int		counter;
}	t_server_mandatory;

typedef struct s_server_bonus
{
	pid_t			current_client;
	unsigned int	letter;
	int				counter;
}	t_server_bonus;

#endif
