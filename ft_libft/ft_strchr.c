/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baran <baran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:37:25 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/20 21:46:56 by baran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*k;

	k = (char *)s;
	c = (unsigned char)c;
	i = 0;
	while (k[i])
	{
		if (k[i] == c)
			return (&k[i]);
		i++;
	}
	if (c == 0)
		return (&k[i]);
	return (0);
}
