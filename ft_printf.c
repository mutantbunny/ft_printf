/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:41 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:50:23 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_code(const char *str, va_list args)
{
	if (*str == 'c')
		return (parse_char(args));
	else if (*str == 's')
		return (parse_string(args));
	else if (*str == 'p')
		return (parse_pointer(args));
	else if (*str == 'd' || *str == 'i')
		return (parse_int(args));
	else if (*str == 'u')
		return (parse_uint(args));
	else if (*str == 'x')
		return (parse_hex(args, LOWERCASE));
	else if (*str == 'X')
		return (parse_hex(args, UPPERCASE));
	else
	{
		write(1, str, 1);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		copied;

	if (str == NULL)
		return (-1);
	len = 0;
	copied = 0;
	va_start(args, str);
	while (str[len] != '\0')
	{
		if (str[len++] != '%')
			continue ;
		write(1, str, len);
		str += len;
		copied += (len + parse_code(str++, args));
		if (str == NULL)
			return (-1);
		len = 0;
	}
	write(1, str, len);
	va_end(args);
	return (copied + len);
}
