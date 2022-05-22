/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:52:50 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/22 04:18:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_int(va_list args, t_format format)
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

int	parse_uint(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_dec_uint(nbr));
}

int	parse_hex_upper(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);

	return (putnbr_hex_uint(nbr, format.flags | UPPERCASE));
}

int	parse_hex_lower(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_hex_uint(nbr, format.flags | LOWERCASE));
}