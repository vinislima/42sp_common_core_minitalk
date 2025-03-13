/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:08:45 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 10:43:28 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			count;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (temp_dest > temp_src && temp_dest < temp_src + n)
	{
		count = n;
		while (count--)
			temp_dest[count] = temp_src[count];
	}
	else
	{
		count = 0;
		while (count < n)
		{
			temp_dest[count] = temp_src[count];
			count++;
		}
	}
	return (dest);
}
