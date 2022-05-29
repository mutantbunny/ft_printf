/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:52:50 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/29 02:23:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_int(va_list args, t_format format)
{
	int	nbr;

	nbr = va_arg(args, int);
	if (nbr >= 0)
		nbr = -nbr;
	else
		format.flags |= MINUS_PREFIX;
	return (putnbr_dec_int(nbr, format));
}

int	parse_uint(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_dec_uint(nbr, format));
}

int	parse_hex_upper(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	format.flags |= UPPERCASE;
	return (putnbr_hex_uint(nbr, format));
}

int	parse_hex_lower(va_list args, t_format format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	format.flags |= LOWERCASE;
	return (putnbr_hex_uint(nbr, format));
}
