/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:29:40 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/17 02:39:38 by gmachado         ###   ########.fr       */
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

	pos = 17;
	if (nbr == 0)
		buf[pos--] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[pos--] = get_hex_digit(nbr & 15, LOWERCASE);
			nbr >>= 4;
		}
	}
	buf[pos--] = 'x';
	buf[pos] = '0';
	write(1, buf + pos, 18 - pos);
	return (18 - pos);
}

int	putnbr_hex_uint(unsigned int nbr, unsigned int flags)
{
	char	buf[10];
	int		pos;

	pos = 9;
	if (nbr == 0)
		buf[pos--] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[pos--] = get_hex_digit(nbr & 15, flags);
			nbr >>= 4;
		}
	}
	if (flags & (UPPERCASE | LEAD_0X))
		buf[pos--] = 'X';
	else
		buf[pos--] = 'x';
	buf[pos] = '0';
	return (write(1, buf + pos, 10 - pos));
}

int	putnbr_dec_uint(unsigned int nbr)
{
	char	buf[11];
	int		pos;

	pos = 10;
	if (nbr == 0)
		buf[pos--] = '0';
	else
	{
		while (nbr != 0)
		{
			buf[pos--] = '0' + (char)(nbr % 10);
			nbr /= 10;
		}
	}
	pos++;
	return (write(1, buf + pos, 11 - pos));
}
