/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:11:54 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/19 01:54:10 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_b.h"

void	player_win(t_data *data, int y, int x, char c)
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
	data->map[y][x] = 'E';
	draw_map(data);
	ft_printf("\n\nYOU WON !!\n\n");
	close_window(data);
}

void	player_killed_s(t_data *data, int y, int x, char c)
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
	data->map[y][x] = 'M';
	draw_map(data);
	ft_printf("\n\nYou got killed by a Saibaman x)\n\n");
	close_window(data);
}

int	load_images(t_data *data)
{
	data->images[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/W_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[0] == NULL)
		return (sprite_errors('W', data, 0), 0);
	data->images[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/0_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[1] == NULL)
		return (sprite_errors('0', data, 1), 0);
	data->images[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/C_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[2] == NULL)
		return (sprite_errors('C', data, 2), 0);
	data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/W_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[3] == NULL)
		return (sprite_errors('W', data, 3), 0);
	load_next_images(data);
	return (0);
}

void	draw_tile(t_data *data, int x, int y, char tile)
{
	int	index;

	index = -1;
	if (tile == '1')
		index = 0;
	else if (tile == '0')
		index = 1;
	else if (tile == 'C')
		index = 2;
	else if (tile == 'E')
		index = 3;
	else if (tile == 'P')
		index = 4;
	else if (tile == 'B')
		index = 5;
	else if (tile == 'M')
		index = 6;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[index], x
		* T_S, y * T_S);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			draw_tile(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
}
