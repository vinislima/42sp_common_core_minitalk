/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:24:28 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/28 15:57:03 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_str = (char *)malloc(1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (s_len - start < len)
		substr_len = s_len - start;
	else
		substr_len = len;
	sub_str = (char *)malloc((substr_len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_memcpy(sub_str, s + start, substr_len);
	sub_str[substr_len] = '\0';
	return (sub_str);
}
