/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:46:51 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/19 01:54:10 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_b.h"

void	player_killed_f(t_data *data, int y, int x, char c)
{
	data->map[y][x] = '0';
	if (c == 'w')
		y -= 1;
	else if (c == 'a')
		x -= 1;
	else if (c == 's')
		y += 1;
	else if (c == 'd')
		x += 1;
	data->map[y][x] = 'B';
	draw_map(data);
	ft_printf("\n\nYou got killed by Frieza :O\n\n");
	close_window(data);
}

int	go_up(int y, int x, t_data *data)
{
	if (y - 1 < 0 || data->map[y - 1][x] == '1')
		return (0);
	if (data->map[y - 1][x] == 'C' && data->nb_coin + 1 == data->total_coin)
	{
		mlx_destroy_image(data->mlx_ptr, data->images[3]);
		data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr,
				"bonus/assets/E_32.xpm", &(int){T_S}, &(int){T_S});
		if (data->images[3] == NULL)
			return (sprite_errors('E', data, 7), 0);
	}
	if (data->map[y - 1][x] == 'C')
		data->nb_coin++;
	if (data->map[y - 1][x] == 'E' && data->nb_coin == data->total_coin)
		player_win(data, y, x, 'w');
	else if (data->map[y - 1][x] == 'E' && data->nb_coin != data->total_coin)
		return (0);
	else if (data->map[y - 1][x] == 'B')
		player_killed_f(data, y, x, 'w');
	else if (data->map[y - 1][x] == 'M')
		player_killed_s(data, y, x, 'w');
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	return (draw_map(data), 1);
}

int	go_left(int y, int x, t_data *data)
{
	if (x - 1 < 0 || data->map[y][x - 1] == '1')
		return (0);
	if (data->map[y][x - 1] == 'C' && data->nb_coin + 1 == data->total_coin)
	{
		mlx_destroy_image(data->mlx_ptr, data->images[3]);
		data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr,
				"bonus/assets/E_32.xpm", &(int){T_S}, &(int){T_S});
		if (data->images[3] == NULL)
			return (sprite_errors('E', data, 7), 0);
	}
	if (data->map[y][x - 1] == 'C')
		data->nb_coin++;
	if (data->map[y][x - 1] == 'E' && data->nb_coin == data->total_coin)
		player_win(data, y, x, 'a');
	else if (data->map[y][x - 1] == 'E' && data->nb_coin != data->total_coin)
		return (0);
	else if (data->map[y][x - 1] == 'B')
		player_killed_f(data, y, x, 'a');
	else if (data->map[y][x - 1] == 'M')
		player_killed_s(data, y, x, 'a');
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'P';
	return (draw_map(data), 1);
}

int	go_down(int y, int x, t_data *data)
{
	if (y + 1 >= data->hauteur || data->map[y + 1][x] == '1')
		return (0);
	if (data->map[y + 1][x] == 'C' && data->nb_coin + 1 == data->total_coin)
	{
		mlx_destroy_image(data->mlx_ptr, data->images[3]);
		data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr,
				"bonus/assets/E_32.xpm", &(int){T_S}, &(int){T_S});
		if (data->images[3] == NULL)
			return (sprite_errors('E', data, 7), 0);
	}
	if (data->map[y + 1][x] == 'C')
		data->nb_coin++;
	if (data->map[y + 1][x] == 'E' && data->nb_coin == data->total_coin)
		player_win(data, y, x, 's');
	else if (data->map[y + 1][x] == 'E' && data->nb_coin != data->total_coin)
		return (0);
	else if (data->map[y + 1][x] == 'B')
		player_killed_f(data, y, x, 's');
	else if (data->map[y + 1][x] == 'M')
		player_killed_s(data, y, x, 's');
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	return (draw_map(data), 1);
}

int	go_right(int y, int x, t_data *data)
{
	if (x + 1 >= data->largeur || data->map[y][x + 1] == '1')
		return (0);
	if (data->map[y][x + 1] == 'C' && data->nb_coin + 1 == data->total_coin)
	{
		mlx_destroy_image(data->mlx_ptr, data->images[3]);
		data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr,
				"bonus/assets/E_32.xpm", &(int){T_S}, &(int){T_S});
		if (data->images[3] == NULL)
			return (sprite_errors('E', data, 7), 0);
	}
	if (data->map[y][x + 1] == 'C')
		data->nb_coin++;
	if (data->map[y][x + 1] == 'E' && data->nb_coin == data->total_coin)
		player_win(data, y, x, 'd');
	else if (data->map[y][x + 1] == 'E' && data->nb_coin != data->total_coin)
		return (0);
	else if (data->map[y][x + 1] == 'B')
		player_killed_f(data, y, x, 'd');
	else if (data->map[y][x + 1] == 'M')
		player_killed_s(data, y, x, 'd');
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'P';
	return (draw_map(data), 1);
}
