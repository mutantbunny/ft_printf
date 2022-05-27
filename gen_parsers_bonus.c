/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_parsers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:45:21 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/27 00:51:28 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_char(va_list args, t_format format)
{
	char	ch;

	ch = (char)va_arg(args, int);

	write(1, &ch, 1);
	return (1);
}

int	parse_pointer(va_list args, t_format format)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	format.flags = (format.flags & JUSTIFY_LEFT) | HEX_PREFIX | LOWERCASE;
	return (putnbr_hex_uint((unsigned long long)ptr, format));
}

int	parse_string(va_list args, t_format format)
{
	int		len;
	char	*arg;

	arg = va_arg(args, char *);
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(arg);
	write(1, arg, len);
	return (len);
}
