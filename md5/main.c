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
	unsigned char 	*tmp;

	tmp = (unsigned char *)&md5->input_md5int[0];
	i = 0;
	ft_bzero(&input_md5chr[0], 64);
	while ((i = read(fd, &input_md5chr[0], 64)))
	{
		ft_printf("\n%d ===> %s\n", i, input_md5chr);
		if (i < 55)
		{
			md5->size += i * 8;
			input_md5chr[i] = 128;
			input_md5chr[57] = 8;
			tmp[3] = input_md5chr[0];
			tmp[2] = input_md5chr[1];
			tmp[57] = input_md5chr[57];
			// memcpy(&md5->input_md5int[0], &input_md5chr[0], 64);
			ft_printf("size -> %x\n", md5->size);

			ft_printf("| %x |\n", input_md5chr[0]);
			ft_printf("| %x |\n", input_md5chr[1]);
			ft_printf("| %x |\n", md5->input_md5int[0]);
			
			// *(unsigned long int *)(&md5->input_md5int[14]) = md5->size;
			
			ft_printf("| %#x | %#x |\n", md5->input_md5int[14], md5->input_md5int[15]);
			break ;
		}
	}
}

int		main(int argc, char **argv)
{
	t_md5 *md5;
	
	md5 = malloc(sizeof(t_md5));
	ft_bzero(md5, sizeof(t_md5));
	if (argc > 1)
	{
		check_command(md5, argv[1]);
		if (argc > 2)
			parsing_argv(md5, argv);
	//	else
	//		work_input(md5);
		check_list(md5->argvs);
	}
	else
		usage("commands");

	ft_printf("%x%x%x%x\n", A, B, C, D);

	take_string_md5(md5, 0);
	formula_md5(md5);
	
	ft_printf("%x%x%x%x\n", A, B, C, D);

	write(1, "\n\n", 2);
	// system("leaks a.out");
	return (0);
}
