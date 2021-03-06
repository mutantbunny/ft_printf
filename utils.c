/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:29:40 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 00:50:38 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_hex_digit(unsigned int digit, unsigned int flags)
{
	const char	upper_digits[17] = "0123456789ABCDEF";
	const char	lower_digits[17] = "0123456789abcdef";

	if (flags & UPPERCASE)
		return (upper_digits[digit]);
	return (lower_digits[digit]);
}

int	putnbr_hex_ptr(unsigned long long nbr)
{
	char	buf[18];
	int		pos;

	pos = 18;
	if (nbr == 0)
		buf[--pos] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[--pos] = get_hex_digit(nbr & 15, LOWERCASE);
			nbr >>= 4;
		}
	}
	buf[--pos] = 'x';
	buf[--pos] = '0';
	write(1, buf + pos, 18 - pos);
	return (18 - pos);
}

int	putnbr_hex_uint(unsigned int nbr, unsigned int flags)
{
	char	buf[10];
	int		pos;

	pos = 10;
	if (nbr == 0)
		buf[--pos] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[--pos] = get_hex_digit(nbr & 15U, flags);
			nbr >>= 4U;
		}
	}
	if (flags & LEAD_0X)
	{
		if (flags & UPPERCASE)
			buf[--pos] = 'X';
		else if (flags & LOWERCASE)
			buf[--pos] = 'x';
		buf[--pos] = '0';
	}
	return (write(1, buf + pos, 10 - pos));
}

int	putnbr_dec_uint(unsigned int nbr)
{
	char	buf[11];
	int		pos;

	pos = 11;
	if (nbr == 0)
		buf[--pos] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[--pos] = '0' + (char)(nbr % 10);
			nbr /= 10;
		}
	}
	return (write(1, buf + pos, 11 - pos));
}
