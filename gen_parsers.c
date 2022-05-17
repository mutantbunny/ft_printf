/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:45:21 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/17 02:45:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_char(char **str, va_list args)
{
	char ch;

	ch = va_arg(args, char);
	write(1, &ch, 1);
	(*str)++;
	return (1);
}

int	parse_pointer(char **str, va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	(*str)++;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (putnbr_hex_ptr((unsigned long long)ptr));
}

int	parse_string(char **str, va_list args)
{
	int		len;
	char	*arg;

	arg = va_arg(args, char *);
	len = ft_strlen(arg);
	write(1, *str, len);
	(*str)++;
	return (len);
}
