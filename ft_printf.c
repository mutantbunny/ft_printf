/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:41 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/16 04:03:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_code(char **str, va_list args, int copied)
{
	if (**str == 'c')
		return (copied + parse_char(str, args));
	else if (**str == 's')
		return (copied + parse_string(str, args));
	else if (**str == 'p')
		return (copied + parse_pointer(str, args));
	else if (**str == 'd' || **str == 'i')
		return (copied + parse_int(str, args));
	else if (**str == 'u')
		return (copied + parse_uint(str, args));
	else if (**str == 'x')
		return (copied + parse_hex(str, args, LOWERCASE));
	else if (**str == 'X')
		return (copied + parse_hex(str, args, UPPERCASE));
	else
	{
		write(1, (*str)++, 1);
		return (copied + 1);
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
	while(str[len] != '\0')
	{
		if (str[len++] != '%')
			continue ;
		write(1, str, len);
		str += len;
		copied += (len + parse_code(&str, args, copied));
		if (str == NULL)
			return (-1);
		len = 0;
	}
	write(1, str, len);
	va_end(args);
	return (copied + len);
}
