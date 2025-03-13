/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:51:57 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 10:44:02 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_str;
	size_t			count;

	temp_str = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		temp_str[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
