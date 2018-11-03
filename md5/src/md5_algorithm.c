/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:28:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/03 17:28:54 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static inline void	twice_last_line(t_md5 *md5, unsigned char *input_md5chr)
{
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
	ft_bzero(&md5->input_md5int[0], 64);
	ft_bzero(input_md5chr, 64);
	ft_memcpy(input_md5chr + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
}

static inline void	last_line(t_md5 *md5, unsigned char *input_md5chr)
{
	ft_memcpy(input_md5chr + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
}

void				take_fd_md5(t_md5 *md5, int fd)
{
	unsigned char	input_md5chr[64];
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	ft_bzero(&input_md5chr[0], 64);
	while ((i = read(fd, &input_md5chr[n], 64 - n)) > 63 || i > 0)
	{
		md5->size += i * 8;
		n += i;
		if (n < 63)
			continue ;
		ft_memcpy(&md5->input_md5int[0], &input_md5chr[0], 64);
		formula_md5(md5);
		ft_bzero(&input_md5chr[0], 64);
		ft_bzero(&md5->input_md5int[0], 64);
		n = 0;
	}
	md5->size += i * 8;
	input_md5chr[n + i] = 128;
	if (i < 56)
		last_line(md5, &input_md5chr[0]);
	else
		twice_last_line(md5, &input_md5chr[0]);
}

// void				take_str_md5(t_md5 *md5)
// {
	
// }
