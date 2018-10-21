#ifndef MD5_H
# define MD5_H

# include "libft/include_lib/libft.h"


static unsigned int g_hash_md5[4] = {
	0x01234567, 0x89ABCDEF,
	0xFEDCBA98, 0x76543210
};


typedef struct	s_argvs
{
	char 			flag;
	char 			*str;
	struct s_argvs	*next;
} 				t_argvs;

typedef struct	s_md5
{
	unsigned int input[16];
}				t_md5;

#endif
