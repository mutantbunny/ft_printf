/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:41 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/25 19:07:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned int	parse_flags(const char **str)
{
	unsigned int	flags;
	char			*s;

	s = *str;
	flags = 0;
	while (s++)
	{
		if (*s == '0')
			flags |= PAD_WITH_ZEROS;
		else if (*s == ' ')
			flags |= SPACE_PREFIX;
		else if (*s == '+')
			flags |= PLUS_PREFIX;
		else if (*s == '-')
			flags |= JUSTIFY_LEFT;
		else if (*s == '#')
			flags |= HEX_PREFIX;
		else
			break ;
	}
	*str = s;
	return (flags);
}

int	parse_width(const char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width += (**str - '0');
		*str++;
	}
	return (width);
}

int	parse_precision(const char **str, t_format *format)
{
	int	precision;

	if (**str != '.')
		return (0);
	*str++;
	format->flags |= PRECISION_SET;
	precision = 0;
	while (ft_isdigit(**str))
	{
		precision += (**str - '0');
		*str++;
	}
	return (precision);
}

int	parse_specifier(const char *str, t_format format, va_list args)
{
	if (*str == '\0')
		return (0);
	else if (*str == 'c')
		return (parse_char(args, format));
	else if (*str == 's')
		return (parse_string(args, format));
	else if (*str == 'p')
		return (parse_pointer(args, format));
	else if (*str == 'd' || *str == 'i')
		return (parse_int(args, format));
	else if (*str == 'u')
		return (parse_uint(args, format));
	else if (*str == 'x')
		return (parse_hex_lower(args, format));
	else if (*str == 'X')
		return (parse_hex_upper(args, format));
	else
	{
		write(1, str, 1);
		return (1);
	}
}

int	parse_format(const char *str, va_list args)
{
	t_format	format;

	format.flags = parse_flags(&str);
	format.width = parse_width(&str);
	format.precision = parse_precision(&str, &format);
	return (parse_specifier(str, format, args));
}
