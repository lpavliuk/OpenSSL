/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_formula.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:42:51 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/01 20:42:52 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

// =============| DELETE IT!!! |================ //

void	write_output_md5(void)
{
	unsigned char *tmp = (unsigned char *)&g_hash_md5[0];
	int i = -1;
	while (++i < 16)	
		ft_printf("%02x", tmp[i]);
	ft_printf("\n");
}

// ============================================= //

void	use_formula(t_md5 *md5, int fd, char string)
{
	md5->flag_data = 1;
	if (md5->command == CMD_MD5)
	{
		(!string) ? take_fd_md5(md5, fd) : take_str_md5(md5);
		write_output_md5(); // DELETE IT!!!
	}
	else if (md5->command == CMD_SHA256)
		;
}
