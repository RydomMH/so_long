/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:17:02 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/16 19:38:23 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlenmap(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_free(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	inivalue(int *exit, int *i, int *j, int *player)
{
	*exit = 0;
	*i = 0;
	*j = 0;
	*player = 0;
}

char	**copy_map(char **map, int ligne)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (ligne + 1));
	if (copy == NULL)
		return (NULL);
	copy[ligne] = 0;
	while (i < ligne)
	{
		copy[i] = ft_strdup(map[i]);
		if (copy[i] == NULL)
			return (ft_free(copy), NULL);
		i++;
	}
	return (copy);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
