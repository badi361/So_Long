/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baran <baran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:45:46 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/26 15:39:44 by baran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ssstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_string(char *str, int *count)
{
	if (!str)
	{
		*count += (write (1, "(null)", 6));
		return ;
	}
	*count += write (1, str, ft_ssstrlen(str));
}
