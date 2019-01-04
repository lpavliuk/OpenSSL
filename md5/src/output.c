/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:55 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/04 21:10:50 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

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
	tmp[32] = '\0';
	ft_printf("%s\n", tmp);
}

void	output_hash_sha256(void)
{
	char			tmp[65];
	char			*hex;
	int				i;
	unsigned int	rev;

	i = -1;
	while (++i < 8)
	{
		rev = rev_bytes(g_hash_sha256[i], 4);
		hex = ft_itoa_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
	}
	tmp[64] = '\0';
	ft_printf("%s\n", tmp);	
}
