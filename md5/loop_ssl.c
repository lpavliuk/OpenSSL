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

void	input_ssl(t_md5 *md5)
{
	char 	**str;
	int		i;

	ft_printf("==> %s\n", md5->line);
	str = ft_strsplit(md5->line, ' ');
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
	ft_printf("{yellow}OpenSSL>{green} ");
	while (get_next_line(0, &md5->line))
	{
		input_ssl(md5);

		update_hashes();
		system("leaks a.out");
		ft_printf("{yellow}OpenSSL>{green} ");
	}
}
