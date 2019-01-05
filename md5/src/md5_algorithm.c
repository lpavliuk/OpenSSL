/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:28:52 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/05 20:19:29 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static inline void	twice_last_line(t_md5 *md5)
{
	ft_memcpy(&md5->input_md5int[0], &md5->input_md5chr[0], 64);
	formula_md5(md5);
	ft_bzero(&md5->input_md5int[0], 64);
	ft_bzero(&md5->input_md5chr[0], 64);
	ft_memcpy(&md5->input_md5chr[0] + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], &md5->input_md5chr[0], 64);
	formula_md5(md5);
}

static inline void	last_line(t_md5 *md5)
{
	ft_memcpy(&md5->input_md5chr[0] + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], &md5->input_md5chr[0], 64);
	formula_md5(md5);
}

static inline void	end(t_md5 *md5, int i, int n)
{
	md5->size += i * 8;
	md5->input_md5chr[n] = 128;
	if (i < 56)
		last_line(md5);
	else
		twice_last_line(md5);
	ft_bzero(&md5->input_md5chr[0], 64);
	ft_bzero(&md5->input_md5int[0], 64);
	md5->size = 0;
	output_hash_md5();
}

void				take_fd_md5(t_md5 *md5)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while ((i = read(md5->fd, &md5->input_md5chr[n], 64 - n)) > 63 || i > 0)
	{
		md5->size += i * 8;
		n += i;
		if (n < 64)
			continue ;
		ft_memcpy(&md5->input_md5int[0], &md5->input_md5chr[0], 64);
		formula_md5(md5);
		ft_bzero(&md5->input_md5chr[0], 64);
		ft_bzero(&md5->input_md5int[0], 64);
		n = 0;
	}
	end(md5, i, n + i);
}

void				take_str_md5(t_md5 *md5)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	n = 0;
	while (i > 0)
	{
		ft_strncpy((char *)&md5->input_md5chr[0], &md5->str[n], 64);
		i = ft_strlen((char *)&md5->input_md5chr[0]);
		n += i;
		if (i < 64)
			break ;
		md5->size += i * 8;
		ft_memcpy(&md5->input_md5int[0], &md5->input_md5chr[0], 64);
		formula_md5(md5);
		ft_bzero(&md5->input_md5chr[0], 64);
		ft_bzero(&md5->input_md5int[0], 64);
	}
	end(md5, i, n);
}
