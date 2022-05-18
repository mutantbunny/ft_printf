/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:52:50 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/17 19:50:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_int(va_list args)
{
	int	nbr;
	int	is_negative;

	nbr = va_arg(args, int);
	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		nbr = -nbr;
		is_negative = 1;
		write(1, "-", 1);
	}
	else
		is_negative = 0;
	return (putnbr_dec_uint(nbr) + is_negative);
}

int	parse_uint(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_dec_uint(nbr));
}

int	parse_hex(va_list args, unsigned int flags)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_hex_uint(nbr, flags));
}
