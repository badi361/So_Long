/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:56:45 by bguzel            #+#    #+#             */
/*   Updated: 2022/11/20 16:24:51 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int c, int *count)
{
	if (c > 9)
	{
		print_unsigned(c / 10, count);
		print_unsigned(c % 10, count);
	}
	else
		print_char(c + 48, count);
}
