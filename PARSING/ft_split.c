/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:35:13 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/16 19:38:23 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_words(char const *str, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i + 1] == c)
			word++;
		if (str[i] != c && str[i + 1] == '\0')
			word++;
		i++;
	}
	return (word);
}

void	write_word(char *split, char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
}

int	write_split(char **split, char const *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			split[word] = malloc(sizeof(char) * j + 1);
			if (split[word] == NULL)
				return (0);
			write_word(split[word], str + i, c);
			i = i + j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		word;
	int		i;

	i = 0;
	if (str[i] == '\0' && c == '\0')
	{
		split = malloc(sizeof(char *) * 1);
		split[0] = NULL;
		if (split == NULL)
			return (NULL);
		return (split);
	}
	word = count_words(str, c);
	split = malloc(sizeof(char *) * (word + 1));
	if (split == NULL)
		return (NULL);
	split[word] = 0;
	if (!write_split(split, str, c))
	{
		free_split(split);
		return (NULL);
	}
	return (split);
}
