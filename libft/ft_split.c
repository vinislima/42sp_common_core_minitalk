/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:11:41 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 11:45:14 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c);
static char		*ft_allocate_word(char const *s, char c);
static void		ft_free_split(char **split, size_t i);
static int		ft_add_word(char **split, size_t *count,
					char const **s, char c);
char			**ft_split(char const *s, char c);

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_allocate_word(char const *s, char c)
{
	size_t	len;
	size_t	count;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	count = 0;
	while (count < len)
	{
		word[count] = s[count];
		count++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free (split);
}

static int	ft_add_word(char **split, size_t *count, char const **s, char c)
{
	split[*count] = ft_allocate_word(*s, c);
	if (!split[*count])
		return (0);
	(*count)++;
	while (**s && **s != c)
		(*s)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	size_t	count;
	char	**split;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	split = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && !ft_add_word(split, &count, &s, c))
		{
			ft_free_split(split, count);
			return (NULL);
		}
	}
	split[count] = NULL;
	return (split);
}
