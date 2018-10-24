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

unsigned int g_hash_md5[4] = {
	0x67452301, 0xEFCDAB89,
	0x98BADCFE, 0x10325476
};

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

	ft_printf("before: %x\n", md5->input[0]);
	read(0, &md5->input, 64);
	ft_printf("after: %x\n", md5->input[0]);
	ft_printf("%x%x%x%x\n", A, B, C, D);
	formula_md5(md5);
	ft_printf("%x%x%x%x\n", A, B, C, D);

	write(1, "\n\n", 2);
	system("leaks a.out");
	return (0);
}
