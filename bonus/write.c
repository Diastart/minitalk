/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:31:43 by dias              #+#    #+#             */
/*   Updated: 2025/02/18 01:37:08 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	write_utf8_4bytes(unsigned int c)
{
	unsigned char	bytes[4];

	bytes[0] = 240 | (c >> 18);
	bytes[1] = 128 | ((c >> 12) & 63);
	bytes[2] = 128 | ((c >> 6) & 63);
	bytes[3] = 128 | (c & 63);
	write(1, bytes, 4);
}

void	write_utf8_3bytes(unsigned int c)
{
	unsigned char	bytes[3];

	bytes[0] = 224 | (c >> 12);
	bytes[1] = 128 | ((c >> 6) & 63);
	bytes[2] = 128 | (c & 63);
	write(1, bytes, 3);
}

void	write_utf8_2bytes(unsigned int c)
{
	unsigned char	bytes[2];

	bytes[0] = 192 | (c >> 6);
	bytes[1] = 128 | (c & 63);
	write(1, bytes, 2);
}
