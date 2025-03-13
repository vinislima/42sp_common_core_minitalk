/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:34 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/28 15:11:00 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while ((char)c != s[count])
	{
		if (s[count] == '\0')
			return (0);
		count++;
	}
	return ((char *)&s[count]);
}
