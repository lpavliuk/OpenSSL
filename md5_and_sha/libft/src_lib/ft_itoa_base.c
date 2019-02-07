/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:21:19 by opavliuk          #+#    #+#             */
/*   Updated: 2019/02/05 19:33:22 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(uintmax_t n, short int base)
{
	int		c;
	char	*str;
	char	*bases;

	bases = "0123456789abcdef";
	c = ft_count(n, base);
	str = (char *)malloc(sizeof(char) * c);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, c);
	str[c] = '\0';
	while (c >= 0)
	{
		str[--c] = bases[n % base];
		n /= base;
	}
	return (str);
}
