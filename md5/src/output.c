/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:55 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/26 20:13:27 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static inline void	print_s(t_md5 *md5, char *hash)
{
	if (md5->command == 1)
		ft_printf("MD5 (\"%s\") = %s\n", md5->str, hash);
	else if (md5->command == 3)
		ft_printf("SHA256 (\"%s\") = %s\n", md5->str, hash);
}

static inline void	print_file(t_md5 *md5, char *hash)
{
	if (md5->command == 1)
		ft_printf("MD5 (%s) = %s\n", md5->str, hash);
	else if (md5->command == 3)
		ft_printf("SHA256 (%s) = %s\n", md5->str, hash);
}

static inline void	output(t_md5 *md5, char *hash)
{
	write(1, "\e[97m", 5);
	if (md5->flags_rqps & FLAG_Q || (!md5->flags_rqps && !md5->flag_file))
		ft_printf("%s\n", hash);
	else if (md5->flag_file && !(md5->flags_rqps & FLAG_R))
		print_file(md5, hash);
	else if (md5->flag_file)
		ft_printf("%s %s\n", hash, md5->str);
	else if (md5->flags_rqps & FLAG_S && !(md5->flags_rqps & FLAG_R))
		print_s(md5, hash);
	else if (md5->flags_rqps & FLAG_S)
		ft_printf("%s \"%s\"\n", hash, md5->str);
	else if (md5->flags_rqps & FLAG_P)
		ft_printf("%s%s\n", md5->str, hash);
	write(1, "\e[0m", 4);
}

void				output_hash_md5(t_md5 *md5)
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

void				output_hash_sha256(t_md5 *md5)
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
