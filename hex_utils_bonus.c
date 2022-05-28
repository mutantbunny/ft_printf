/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:29:40 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/27 18:15:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_hex_left_justified(char *s, int len, t_format format, int num_zeros)
{
	int	num_spaces;
	int	copied;

	copied = 0;
	num_spaces = format.width - num_zeros - len;
	if (format.flags & HEX_PREFIX)
	{
		num_spaces -= 2;
		if (format.flags & UPPERCASE)
			copied = write(1, "0X", 2);
		else if (format.flags & LOWERCASE)
			copied = write(1, "0x", 2);
	}
	copied += write_repeated('0', num_zeros);
	copied += write(1, s, len);
	return (copied + write_repeated(' ', num_spaces));
}

int	write_hex_right_justified(char *s, int len, t_format format, int num_zeros)
{
	int	num_spaces;
	int	copied;

	num_spaces = format.width - num_zeros - len;
	if (format.flags & HEX_PREFIX)
		num_spaces -= 2;
	copied = write_repeated(' ', num_spaces);
	if (format.flags & HEX_PREFIX)
	{
		if (format.flags & UPPERCASE)
			copied += write(1, "0X", 2);
		else if (format.flags & LOWERCASE)
			copied += write(1, "0x", 2);
	}
	copied += write_repeated('0', num_zeros);
	return (copied + write(1, s, len));
}

int	write_hex_padded(char *s, int len, t_format format)
{
	int	remaining;
	int	num_zeros;

	if ((format.flags & PRECISION_SET))
		num_zeros = format.precision - len;
	else if (format.flags & (PAD_WITH_ZEROS | !JUSTIFY_LEFT))
	{
		num_zeros = format.width - len;
		if (format.flags & HEX_PREFIX)
			num_zeros -= 2;
	}
	else
		num_zeros = 0;
	if (format.flags & JUSTIFY_LEFT)
		return (write_hex_left_justified(s, len, format, num_zeros));
	else
		return (write_hex_right_justified(s, len, format, num_zeros));
}

char	get_hex_digit(unsigned int digit, t_format format)
{
	const char	upper_digits[17] = "0123456789ABCDEF";
	const char	lower_digits[17] = "0123456789abcdef";

	if (format.flags & UPPERCASE)
		return (upper_digits[digit]);
	return (lower_digits[digit]);
}

int	putnbr_hex_uint(unsigned int nbr, t_format format)
{
	char	buf[16];
	int		pos;

	pos = 16;
	if (nbr == 0)
		buf[--pos] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[--pos] = get_hex_digit(nbr & 15U, format);
			nbr >>= 4U;
		}
	}
	return (write_hex_padded(buf + pos, 16 - pos, format));
}