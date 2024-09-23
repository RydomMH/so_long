/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:16:18 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 11:51:53 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(char **map, int *Px, int *Py)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	*Px = x;
	*Py = y;
}

int	algorithme(char **map, t_flood_fill *data, int Px, int Py)
{
	if (Px < 0 || Py < 0 || map[Py] == 0 || map[Py][Px] == 0)
		return (0);
	if (map[Py][Px] == '1' || map[Py][Px] == 'V')
		return (0);
	if (map[Py][Px] == 'C')
		data->nb_coin++;
	if (map[Py][Px] == 'E')
	{
		data->exit_found = 1;
		return (0);
	}
	map[Py][Px] = 'V';
	algorithme(map, data, Px + 1, Py);
	algorithme(map, data, Px - 1, Py);
	algorithme(map, data, Px, Py + 1);
	algorithme(map, data, Px, Py - 1);
	return (0);
}

int	flood_fill(char **map, t_data *data_bis)
{
	int				y;
	int				x;
	t_flood_fill	data;
	char			**temp;
	int				ligne;

	ligne = 0;
	y = 0;
	x = 0;
	data.nb_coin = 0;
	data.exit_found = 0;
	while (map[ligne] != 0)
		ligne++;
	temp = copy_map(map, ligne);
	if (temp == NULL)
		return (-1);
	player_pos(temp, &x, &y);
	algorithme(temp, &data, x, y);
	if (data.nb_coin != data_bis->total_coin || data.exit_found == 0)
		return (ft_printf("Error\n\nNo reachable exit or coin\n\n"),
			ft_free(temp), temp = NULL, -1);
	return (ft_free(temp), temp = NULL, 0);
}
