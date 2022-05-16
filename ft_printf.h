/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:55 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/16 02:37:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define SPECIFIER 1
# define INVALID 0
# define LOWERCASE 0
# define UPPERCASE 1
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

int	ft_printf(const char *str, ...);
int parse_char(char **str, va_list args);
int parse_hex(char **str, va_list args, int letter_case);
int parse_int(char **str, va_list args);
int parse_pointer(char **str, va_list args);
int parse_string(char **str, va_list args);
int parse_uint(char **str, va_list args);
#endif