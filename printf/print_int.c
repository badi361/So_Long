/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:32:27 by bguzel            #+#    #+#             */
/*   Updated: 2022/11/20 16:24:43 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		print_char('-', count);
	}
	if (n > 9)
	{
		print_int(n / 10, count);
		print_int(n % 10, count);
	}
	else
		print_char(n + 48, count);
}
