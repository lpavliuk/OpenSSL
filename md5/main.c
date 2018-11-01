/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:00:34 by opavliuk          #+#    #+#             */
/*   Updated: 2018/10/22 17:00:35 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

// =============| DELETE IT!!! |================ //
void	check_list(t_argvs *argvs)
{
	t_argvs *tmp;

	tmp = argvs;
	while (tmp)
	{
		ft_printf("%x ", (unsigned char)tmp->flag);
		if (tmp->str)
			ft_printf("==> %s\n", tmp->str);
		else
			ft_printf("\n");
		tmp = tmp->next;
	}
}

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



/*
** -p : Читает из INPUT и выводит то что считал и хэш
** -s : Читает следущий аргумент для хэширования
** "MD5 ("text") = hash\n"
** "SHA256 ("text") = hash\n"
** -r : Вначале хэш, потом имя файла или текст
** -q : Выводит только хэш и имеет приоритет перед
*/

unsigned int g_hash_md5[4] = {
	0x67452301, 0xEFCDAB89,
	0x98BADCFE, 0x10325476
};

void	take_string_md5(t_md5 *md5, int fd)
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

void	update_hashes(void)
{
	g_hash_md5[0] = 0x67452301;
	g_hash_md5[1] = 0xEFCDAB89;
	g_hash_md5[2] = 0x98BADCFE;
	g_hash_md5[3] = 0x10325476;
}

void	free_md5(t_md5 *md5)
{
	t_argvs *tmp;

	while (md5->argvs)
	{
		tmp = md5->argvs->next;
		if (md5->argvs->str)
			free(md5->argvs->str);
		free(md5->argvs);
		md5->argvs = tmp;
	}
	free(md5->line);
	ft_bzero(md5, sizeof(t_md5));
}

void	use_formula(t_md5 *md5)
{
	if (md5->command == CMD_MD5)
	{
		take_string_md5(md5, 0);
		write_output_md5(); // DELETE IT!!!
	}
	else if (md5->command == CMD_SHA256)
		;
}

void	parsing_input(t_md5 *md5)
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
	
	check_list(md5->argvs); // DELETE IT!!!
	ft_printf("ok1\n");
	
	use_formula(md5);
	while (i > -1)
		free(str[i--]);
	free(str);
	free_md5(md5);
}

void	loop(t_md5 *md5)
{
	ft_printf("OpenSSL> ");
	while (get_next_line(0, &md5->line))
	{
		parsing_input(md5);

		update_hashes();
		system("leaks a.out");
		ft_printf("OpenSSL> ");
	}
}

int		main(void)
{
	t_md5 *md5;
	
	md5 = malloc(sizeof(t_md5));
	ft_bzero(md5, sizeof(t_md5));
	
	loop(md5);

	return (0);
}
