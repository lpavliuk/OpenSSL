/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:55 by opavliuk          #+#    #+#             */
/*   Updated: 2019/02/05 19:39:11 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static inline void	print_s(t_md5 *md5)
{
	if (md5->command == 1)
		ft_printf("MD5 (\"%s\") = ", md5->str);
	else if (md5->command == 3)
		ft_printf("SHA256 (\"%s\") = ", md5->str);
	else if (md5->command == 5)
		ft_printf("SHA224 (\"%s\") = ", md5->str);
}

static inline void	print_file(t_md5 *md5)
{
	if (md5->command == 1)
		ft_printf("MD5 (%s) = ", md5->str);
	else if (md5->command == 3)
		ft_printf("SHA256 (%s) = ", md5->str);
	else if (md5->command == 5)
		ft_printf("SHA224 (%s) = ", md5->str);
}

static inline void	output(t_md5 *md5, char *hash, int len)
{
	write(1, "\e[97m", 5);
	if (md5->flags_rqps & FLAG_Q && md5->flag_now & FLAG_P)
		ft_printf("%s", md5->str);
	else if (md5->flag_file && !(md5->flags_rqps & FLAG_R)
		&& !(md5->flags_rqps & FLAG_Q))
		print_file(md5);
	else if (md5->flag_now & FLAG_S && !(md5->flags_rqps & FLAG_R)
		&& !(md5->flags_rqps & FLAG_Q))
		print_s(md5);
	else if (md5->flag_now & FLAG_P && md5->flags_rqps & FLAG_P)
		ft_printf("%s", md5->str);
	write(1, hash, len);
	if (md5->flags_rqps & FLAG_R && md5->flag_file
		&& !(md5->flags_rqps & FLAG_Q))
		ft_printf(" %s", md5->str);
	else if (md5->flags_rqps & FLAG_R && md5->flag_now & FLAG_S
		&& !(md5->flags_rqps & FLAG_Q))
		ft_printf(" \"%s\"", md5->str);
	write(1, "\e[0m\n", 5);
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
	output(md5, &tmp[0], 32);
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
		if (md5->command == 3)
			rev = rev_bytes(g_hash_sha256[i], 4);
		else
			rev = rev_bytes(g_hash_sha224[i], 4);
		hex = ft_itoa_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
	}
	if (md5->command == 3)
		output(md5, &tmp[0], 64);
	else
		output(md5, &tmp[0], 56);
}
