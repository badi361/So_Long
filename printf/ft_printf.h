/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baran <baran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:26:15 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/26 15:39:27 by baran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	print_int(int n, int *count);
void	print_char(char d, int *count);
void	print_string(char *str, int *count);
void	print_unsigned(unsigned int c, int *count);
void	print_ptr(unsigned long ptr, int *count);
void	print_hex(unsigned long value, char c, int *count);
int		ft_ssstrlen(char *str);
#endif