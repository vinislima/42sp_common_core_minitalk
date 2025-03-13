/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:24 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 10:42:42 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;
	size_t				count;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (temp_s1[count] != temp_s2[count])
			return (temp_s1[count] - temp_s2[count]);
		count++;
	}
	return (0);
}
