/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:28:57 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:36:59 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_utf8_4bytes(pid_t pid, unsigned char byte, char *str, int *i)
{
	unsigned int	c;

	c = ((byte & 0x07) << 18) | ((str[*i + 1] & 0x3F) << 12)
		| ((str[*i + 2] & 0x3F) << 6) | (str[*i + 3] & 0x3F);
	send_char(pid, c);
	*i += 3;
}

void	send_utf8_3bytes(pid_t pid, unsigned char byte, char *str, int *i)
{
	unsigned int	c;

	c = ((byte & 0x0F) << 12) | ((str[*i + 1] & 0x3F) << 6)
		| (str[*i + 2] & 0x3F);
	send_char(pid, c);
	*i += 2;
}

void	send_utf8_2bytes(pid_t pid, unsigned char byte, char *str, int *i)
{
	unsigned int	c;

	c = ((byte & 0x1F) << 6) | (str[*i + 1] & 0x3F);
	send_char(pid, c);
	*i += 1;
}

void	send_string(pid_t pid, char *str)
{
	int				i;
	unsigned char	byte;

	i = 0;
	while (str[i])
	{
		byte = str[i];
		if ((byte & 0x80) == 0)
			send_char(pid, byte);
		else if ((byte & 0xE0) == 0xC0)
			send_utf8_2bytes(pid, byte, str, &i);
		else if ((byte & 0xF0) == 0xE0)
			send_utf8_3bytes(pid, byte, str, &i);
		else if ((byte & 0xF8) == 0xF0)
			send_utf8_4bytes(pid, byte, str, &i);
		i++;
	}
	send_char(pid, '\0');
}
