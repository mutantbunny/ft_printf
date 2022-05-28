/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:29:40 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/27 18:17:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_dec_left_justified(char *s, int len, t_format format, int num_zeros)
{
	int	num_spaces;
	int	copied;

	copied = 0;
	num_spaces = format.width - num_zeros - len;
	if (format.flags & (MINUS_PREFIX | PLUS_PREFIX | SPACE_PREFIX))
		num_spaces--;
	if (format.flags & (MINUS_PREFIX))
		copied = write(1, "-", 1);
	else if (format.flags & (PLUS_PREFIX))
		copied = write(1, "+", 1);
	else if (format.flags & (SPACE_PREFIX))
		copied = write(1, " ", 1);
	copied += write_repeated('0', num_zeros);
	copied += write(1, s, len);
	return (copied + write_repeated(' ', num_spaces));
}

int	write_dec_right_justified(char *s, int len, t_format format, int num_zeros)
{
	int	num_spaces;
	int	copied;

	num_spaces = format.width - num_zeros - len;
	if (format.flags & (MINUS_PREFIX | PLUS_PREFIX | SPACE_PREFIX))
		num_spaces--;

	copied = write_repeated(' ', num_spaces);
	if (format.flags & (MINUS_PREFIX))
		copied += write(1, "-", 1);
	else if (format.flags & (PLUS_PREFIX))
		copied += write(1, "+", 1);
	else if (format.flags & (SPACE_PREFIX))
		copied += write(1, " ", 1);
	copied += write_repeated('0', num_zeros);
	return (copied + write(1, s, len));
}

int	write_dec_padded(char *s, int len, t_format format)
{
	int	remaining;
	int	num_zeros;

	if ((format.flags & PRECISION_SET))
		num_zeros = format.precision - len;
	else if (format.flags & (PAD_WITH_ZEROS | !JUSTIFY_LEFT))
	{
		num_zeros = format.width - len;
		if (MINUS_PREFIX | PLUS_PREFIX)
			num_zeros--;
	}
	else
		num_zeros = 0;
	if (format.flags & JUSTIFY_LEFT)
		return (write_dec_left_justified(s, len, format, num_zeros));
	else
		return (write_dec_right_justified(s, len, format, num_zeros));
}

int	putnbr_dec_uint(unsigned int nbr, t_format format)
{
	char	buf[10];
	int		pos;

	pos = 11;
	if (nbr == 0)
		buf[--pos] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[--pos] = '0' - (char)(nbr % 10);
			nbr /= 10;
		}
	}
	return (write_dec_padded(buf + pos, 10 - pos, format));
}
