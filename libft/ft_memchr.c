/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:12:21 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 10:42:25 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pointer;
	size_t				count;

	pointer = s;
	count = 0;
	while (count < n)
	{
		if (pointer[count] == (unsigned char)c)
			return ((void *)(pointer + count));
		count++;
	}
	return (NULL);
}
