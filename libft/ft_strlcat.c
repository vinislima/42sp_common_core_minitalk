/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:30:52 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/24 09:05:21 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	count = 0;
	while (count < (size - dst_len - 1) && src[count] != '\0')
	{
		dst[dst_len + count] = src[count];
		count++;
	}
	if ((dst_len + count) < size)
		dst[dst_len + count] = '\0';
	return (dst_len + src_len);
}
