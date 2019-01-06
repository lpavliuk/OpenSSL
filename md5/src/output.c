/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:55 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/06 19:40:13 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	output(t_md5 *md5, char *hash)
{
	if (!md5->flags_rqps)
		ft_printf("%s\n", hash);
	else if (md5->flags_rqps & FLAG_P)
		ft_printf("%s%s\n", md5->str, hash);
}

void	output_hash_md5(t_md5 *md5)
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
	output(md5, &tmp[0]);
}

void	output_hash_sha256(t_md5 *md5)
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
	output(md5, &tmp[0]);
}
