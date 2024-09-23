/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mvt_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:48 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 16:48:56 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_b.h"

void	display_step_count(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->pas);
	if (steps == NULL)
		close_window(data);
	draw_map(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFF0000, "STEPS :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 10, 0xFF0000, steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10 + 1, 10, 0xFF0000,
		"STEPS :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60 + 1, 10, 0xFF0000, steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10 + 1, 0xFF0000,
		"STEPS :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 10 + 1, 0xFF0000, steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10 + 1, 10 + 1, 0xFF0000,
		"STEPS:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60 + 1, 10 + 1, 0xFF0000,
		steps);
	free(steps);
	steps = NULL;
}

int	handle_input(int keysym, t_data *data)
{
	int	x;
	int	y;
	int	moved;

	moved = 0;
	player_pos(data->map, &x, &y);
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_w && data->map[y - 1][x] != '1')
		moved = go_up(y, x, data);
	else if (keysym == XK_a && data->map[y][x - 1] != '1')
		moved = go_left(y, x, data);
	else if (keysym == XK_s && data->map[y + 1][x] != '1')
		moved = go_down(y, x, data);
	else if (keysym == XK_d && data->map[y][x + 1] != '1')
		moved = go_right(y, x, data);
	if (moved == 1)
	{
		data->pas++;
		display_step_count(data);
	}
	return (0);
}

int	launch_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->pas = 0;
	data->res_height = 0;
	data->res_width = 0;
	if (data->mlx_ptr == NULL)
		return (mlx_error(data, 1), 0);
	if (res_calculator(data) == -1)
		return (mlx_error(data, 3), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->res_width,
			data->res_height, "So Long Super Z");
	if (data->win_ptr == NULL)
		return (mlx_error(data, 2), 0);
	load_images(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &close_window,
		data);
	draw_map(data);
	mlx_loop(data->mlx_ptr);
	return (close_window(data), 0);
}
