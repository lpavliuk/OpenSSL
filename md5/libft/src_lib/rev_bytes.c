/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:48:51 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/02 12:48:52 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		rev_bytes(const unsigned int x, const char bytes)
{
	unsigned int	reversed;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&x;
	n2 = (unsigned char *)&reversed;
	if (bytes == 2)
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	else
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	return ((bytes == 1) ? x : reversed);
}
