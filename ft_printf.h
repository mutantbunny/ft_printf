/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:55 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:51:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define SPECIFIER 1
# define INVALID 0

# define UPPERCASE 1U
# define LOWERCASE 2U
# define LEAD_0X 4U

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

int		ft_printf(const char *str, ...);
int		parse_code(const char *str, va_list args);
int		parse_char(va_list args);
int		parse_pointer(va_list args);
int		parse_string(va_list args);
int		parse_int(va_list args);
int		parse_uint(va_list args);
int		parse_hex(va_list args, unsigned int flags);
char	get_hex_digit(unsigned int digit, unsigned int flags);
int		putnbr_hex_ptr(unsigned long long nbr);
int		putnbr_hex_uint(unsigned int nbr, unsigned int flags);
int		putnbr_dec_uint(unsigned int nbr);

#endif