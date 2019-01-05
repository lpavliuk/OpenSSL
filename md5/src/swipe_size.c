/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swipe_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:18:14 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/05 20:18:46 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		swipe_size(unsigned long int *size)
{
	unsigned long int	reversed;
	unsigned char		*n1;
	unsigned char		*n2;

	reversed = *size;
	n1 = (unsigned char *)size;
	n2 = (unsigned char *)&reversed;
	n2[0] = n1[7];
	n2[1] = n1[6];
	n2[2] = n1[5];
	n2[3] = n1[4];
	n2[4] = n1[3];
	n2[5] = n1[2];
	n2[6] = n1[1];
	n2[7] = n1[0];
	*size = reversed;
}
