/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:17:57 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 16:57:15 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_backslash_n(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
		return (ft_printf("Error\n\nBack/n at the top of the map\n\n"), -1);
	while (map[i] != '\0')
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'E' && map[i] != 'P'
			&& map[i] != 'C' && map[i] != '\n')
			return (ft_printf("Error\n\n'%c' in the map\n\n", map[i]), -1);
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (ft_printf("Error\n\nConsecutive backslash n\n\n"), -1);
		i++;
	}
	if (map[i - 1] == '\n')
		return (ft_printf("Error\n\nBack/n at the end of the map\n\n"), -1);
	return (0);
}

int	inside_map(char **map, int *coin)
{
	int	exit;
	int	i;
	int	j;
	int	player;

	inivalue(&exit, &i, &j, &player);
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				*coin += 1;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		j = 0;
		i++;
	}
	if (exit != 1 || player != 1 || *coin == 0)
		return (ft_printf("Error\n\nWith player/exit/coin\n\n"), -1);
	ft_printf("There is/are %d coin(s) in the map\n\n", *coin);
	return (0);
}

int	verif_contour(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->largeur)
	{
		if (map[i][j] != '1' || map[data->hauteur - 1][j] != '1')
			return (ft_printf("Error\n\nWidth's contour\n\n"), -1);
		j++;
	}
	while (i < data->hauteur)
	{
		if (map[i][0] != '1' || map[i][data->largeur - 1] != '1')
			return (ft_printf("Error\n\nHeight's contour\n\n"), -1);
		i++;
	}
	ft_printf("NO WIDTH CONTOUR ERROR\n\n");
	return (0);
}

int	verif_map(char **map, t_data *data)
{
	int	i;

	data->total_coin = 0;
	i = 0;
	data->largeur = ft_strlenmap(map[i]);
	data->hauteur = 0;
	while (map[i] != NULL)
	{
		if (ft_strlenmap(map[i]) != data->largeur)
			return (ft_printf("Error\n\nNot same length in the map\n\n"), -1);
		i++;
		data->hauteur++;
	}
	ft_printf("Map's widht : %d\n", data->largeur);
	ft_printf("Map's height : %d\n\n", data->hauteur);
	if (verif_contour(map, data) == -1)
		return (-1);
	if (inside_map(map, &data->total_coin) == -1)
		return (-1);
	return (flood_fill(map, data));
}

char	**is_map_valid(int fd, t_data *data)
{
	char	*map_bn;
	char	**map;

	map_bn = get_next_line(fd);
	if (map_bn == NULL)
		return (NULL);
	ft_printf("DISPLAY OF MAP WITH BACKSLASH N\n\n");
	ft_printf("%s\n\n", map_bn);
	if (verif_backslash_n(map_bn) == -1)
		return (free(map_bn), map_bn = NULL, NULL);
	map = ft_split(map_bn, '\n');
	if (map == NULL)
		return (free(map_bn), map_bn = NULL, NULL);
	if (verif_map(map, data) == -1)
		return (free(map_bn), map_bn = NULL, ft_free(map), map = NULL, NULL);
	return (free(map_bn), map_bn = NULL, map);
}
