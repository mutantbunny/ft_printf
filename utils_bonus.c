/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:29:40 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/26 20:24:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int write_repeated (char ch, int num_ch)
{
	int count;

	count = 0;
	while (count < num_ch)
	{
		write(1, &ch, 1);
		count++;
	}
	return (count);
}
