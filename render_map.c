/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:11:54 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/16 19:38:23 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_data *data)
{
	data->images[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/W_32.xpm",
			&(int){T_S}, &(int){T_S});
	if (data->images[0] == NULL)
		return (sprite_errors('W', data, 0), 0);
	data->images[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/0_32.xpm",
			&(int){T_S}, &(int){T_S});
	if (data->images[1] == NULL)
		return (sprite_errors('0', data, 1), 0);
	data->images[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/C_32.xpm",
			&(int){T_S}, &(int){T_S});
	if (data->images[2] == NULL)
		return (sprite_errors('C', data, 2), 0);
	data->images[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/W_32.xpm",
			&(int){T_S}, &(int){T_S});
	if (data->images[3] == NULL)
		return (sprite_errors('W', data, 3), 0);
	data->images[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/P_32.xpm",
			&(int){T_S}, &(int){T_S});
	if (data->images[4] == NULL)
		return (sprite_errors('P', data, 4), 0);
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
