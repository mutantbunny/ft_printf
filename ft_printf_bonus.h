/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:55 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/26 22:57:13 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define UPPERCASE 1U
# define LOWERCASE 2U
# define PAD_WITH_ZEROS 4U
# define HEX_PREFIX 8U
# define MINUS_PREFIX 16U
# define PLUS_PREFIX 32U
# define SPACE_PREFIX 64U
# define JUSTIFY_LEFT 128U
# define PRECISION_SET 256U

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_format
{
	int				width;
	int				precision;
	unsigned int	flags;
}	t_format;

unsigned int	parse_flags(const char **str);
int				parse_width(const char **str);
int				parse_precision(const char **str, t_format *format);
int				parse_specifier(const char *str, t_format format, va_list args);
int				parse_format(const char *str, va_list args);
int				parse_char(va_list args, t_format format);
int				parse_pointer(va_list args, t_format format);
int				parse_string(va_list args, t_format format);
int				parse_int(va_list args, t_format format);
int				parse_uint(va_list args, t_format format);
int				parse_hex(va_list args, t_format format);
char			get_hex_digit(unsigned int digit, t_format format);
int				putnbr_hex_ptr(unsigned long long nbr);
int				putnbr_hex_uint(unsigned int nbr, t_format format);
int				putnbr_dec_uint(unsigned int nbr, t_format format);

#endif