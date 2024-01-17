/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:06:05 by bguzel            #+#    #+#             */
/*   Updated: 2022/11/20 16:10:22 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_killer(unsigned int value, char c, int *count)
{
	if (c == 'X')
	{
		if (value > 9)
			print_char((int)value + 55, count);
		else
			print_char((int)value + 48, count);
	}
	else
	{
		if (value > 9)
			print_char((int)value + 55 + 32, count);
		else
			print_char((int)value + 48, count);
	}
}

void	print_hex(unsigned long value, char c, int *count)
{
	if (c != 'p')
		value = (unsigned int) value;
	if (value >= 16)
	{
		print_hex(value / 16, c, count);
		print_hex(value % 16, c, count);
	}
	else
		norm_killer(value, c, count);
}
