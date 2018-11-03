/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:55 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/03 21:18:56 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	output_hash_md5(void)
{
	char			tmp[33];
	char			*hex;
	int				i;
	unsigned int	rev;

	i = -1;
	while (++i < 4)
	{
		rev = rev_bytes(g_hash_md5[i], 4);
		hex = ft_itoa_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
	}
	ft_printf("%s\n", tmp);
}
