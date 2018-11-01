/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ssl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:40:02 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/01 20:40:03 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
// =============| DELETE IT!!! |================ //

void	check_binary(unsigned char *tmp)
{
	int i = -1;
	while (++i < 64)
	{
		ft_printf("%d - %x\n", i, tmp[i]);
	}
	ft_printf("\n");
}

void	write_output_md5(void)
{
	unsigned char *tmp = (unsigned char *)&g_hash_md5[0];
	int i = -1;
	while (++i < 16)	
		ft_printf("%02x", tmp[i]);
	ft_printf("\n");
}

// ============================================= //

void	take_fd_md5(t_md5 *md5, int fd)
{
	unsigned char	input_md5chr[64];
	unsigned int	i;

	i = 0;
	ft_bzero(&input_md5chr[0], 64);
	while (1)
	{
		i = read(fd, &input_md5chr[0], 64);
		ft_printf("\n%d ===> %s\n", i, input_md5chr);
	//	if (i == -1)
	//		ft_error();
		if (i < 55)
		{
			md5->size += i * 8;
			input_md5chr[i] = 128;
			ft_memcpy(&input_md5chr[56], (char *)&md5->size, 8);
			ft_memcpy(&md5->input_md5int[0], &input_md5chr[0], 64);
			formula_md5(md5);
			break ;
		}
	}
}

void	input_ssl(t_md5 *md5)
{
	char 	**str;
	int		i;

	ft_printf("==> %s\n", md5->line);
	str = ft_strsplit(md5->line, ' ');
	i = 0;
	if (str && str[0])
		check_command(md5, str[0]);
	if (md5->command && str && str[1])
		parsing_argv(md5, &str[1], &i);
	else
		use_formula(md5, 0);
	
	ft_printf("free!\n");

	while (i > -1)
		free(str[i--]);
	free(str);
	free(md5->line);
	ft_bzero(md5, sizeof(t_md5));
}

void	loop_ssl(t_md5 *md5)
{
	ft_printf("OpenSSL> ");
	while (get_next_line(0, &md5->line))
	{
		input_ssl(md5);

		update_hashes();
		system("leaks a.out");
		ft_printf("OpenSSL> ");
	}
}
