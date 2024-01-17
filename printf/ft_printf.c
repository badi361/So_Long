/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:25:00 by bguzel            #+#    #+#             */
/*   Updated: 2022/11/22 15:01:02 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(va_list s, char c, int *count)
{
	if (c == 'd' || c == 'i')
		print_int(va_arg(s, int), count);
	else if (c == 'c')
		print_char(va_arg(s, int), count);
	else if (c == 's')
		print_string(va_arg(s, char *), count);
	else if (c == 'u')
		print_unsigned(va_arg(s, unsigned int), count);
	else if (c == 'p')
		print_ptr(va_arg(s, unsigned long), count);
	else if (c == 'X' || c == 'x')
		print_hex(va_arg(s, unsigned int), c, count);
	else if (c == '%')
		print_char('%', count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	lst;

	va_start(lst, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			formatter(lst, s[++i], &count);
		else
			print_char(s[i], &count);
		i++;
	}
	va_end(lst);
	return (count);
}
