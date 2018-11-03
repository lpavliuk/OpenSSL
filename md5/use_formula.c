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

void	twice_formula(t_md5 *md5, unsigned char	*input_md5chr, int i)
{
	input_md5chr[i] = 128;
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
	ft_bzero(&md5->input_md5int[0], 64);
	ft_bzero(input_md5chr, 64);
	ft_memcpy(input_md5chr + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
}

void	last_line(t_md5 *md5, unsigned char	*input_md5chr, int i)
{
	input_md5chr[i] = 128;
	ft_memcpy(input_md5chr + 56, (char *)&md5->size, 8);
	ft_memcpy(&md5->input_md5int[0], input_md5chr, 64);
	formula_md5(md5);
}

void	take_fd_md5(t_md5 *md5, int fd)
{
	unsigned char	input_md5chr[64];
	unsigned int	i;

	i = 0;
	while (1)
	{
		ft_bzero(&input_md5chr[0], 64);
		ft_bzero(&md5->input_md5int[0], 64);
		i = read(fd, &input_md5chr[0], 64);
		ft_printf("\n%d ===> %s\n", i, input_md5chr);
		md5->size += i * 8;
		ft_printf("size: => %d\n", md5->size);
		if (i < 56)
		{
			last_line(md5, &input_md5chr[0], i);
			break ;
		}
		else if (i >= 56 && i < 64)
		{
			twice_formula(md5, &input_md5chr[0], i);
			break ;
		}
		ft_memcpy(&md5->input_md5int[0], &input_md5chr[0], 64);
		formula_md5(md5);
	}
}

void	use_formula(t_md5 *md5, int fd, char string)
{
	md5->flag_data = 1;
	if (md5->command == CMD_MD5)
	{
		(!string) ?	take_fd_md5(md5, fd) : 0;
		write_output_md5(); // DELETE IT!!!
	}
	else if (md5->command == CMD_SHA256)
		;
}
