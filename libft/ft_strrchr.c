/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:24 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 09:19:40 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;

	count = ft_strlen(s);
	while (count + 1)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count--;
	}
	return (NULL);
}
