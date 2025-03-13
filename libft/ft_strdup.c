/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:32:49 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/26 15:26:55 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = (char *)ft_calloc(len, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}
