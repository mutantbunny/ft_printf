/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:45:21 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/16 04:03:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_char(char **str, va_list args)
{
	write(1, va_arg(args, char), 1);
	(*str)++;
	return (1);
}

int parse_pointer(char **str, va_list args)
{
	unsigned long long ptr;

	ptr = (unsigned long long)va_arg(args, void *);
	(*str)++;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (putnbr_hex_ptr(ptr));
}

int parse_string(char **str, va_list args)
{
	int len;
	char *arg;

	arg = va_arg(args, char *);
	len = ft_strlen(arg);
	write(1, *str, len);
	(*str) += len;
	return (len);
}
