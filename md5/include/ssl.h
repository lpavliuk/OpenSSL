/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:00:42 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/03 20:59:49 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# include "../libft/include_lib/libft.h"
# include <fcntl.h>

# define NUM_CMDS 2

# define FLAG_P 0x01
# define FLAG_S 0x02
# define FLAG_R 0x04
# define FLAG_Q 0x08

# define A g_hash_md5[0]
# define B g_hash_md5[1]
# define C g_hash_md5[2]
# define D g_hash_md5[3]
# define TMD5 g_table_md5

static char				*g_cmd[NUM_CMDS] = {
	"md5", "sha256"
};

unsigned int				g_hash_md5[4];

static const unsigned int	g_table_md5[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

unsigned int				g_hash_sha256[8];

static const unsigned int	g_table_sha256[64] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

typedef struct				s_md5
{
	unsigned int		input_md5int[16];
	unsigned char		input_md5chr[64];
	unsigned long int	size;
	int					fd;
	char				*str;
	char				flags_rqps;
	char				flag_data;
	char				flag_usage;
	char				*line;
	char				command;
}							t_md5;

void						argvs(t_md5 *md5, char **argv);
void						loop_ssl(t_md5 *md5);
void						usage(char *str);
void						output_hash_md5(void);
void						take_fd_md5(t_md5 *md5);
void						take_str_md5(t_md5 *md5);
void						take_str_sha256(t_md5 *md5);
void						take_fd_sha256(t_md5 *md5);
void						dispatcher_cmd(t_md5 *md5, char string);
void						formula_md5(t_md5 *md5);
void						formula_sha256(t_md5 *md5);
void						parsing_argv(t_md5 *md5, char **argv, int *i);
void						check_command(t_md5 *md5, char *argv);
void						check_flags(t_md5 *md5, char **argv, int *i);
void						update_hashes(void);
void						free_md5(t_md5 *md5);

static void				(*g_func[NUM_CMDS * 2])(t_md5 *md5) = {
	take_fd_md5, take_str_md5, take_fd_sha256, take_str_sha256
};

#endif
