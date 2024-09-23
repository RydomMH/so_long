/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:18 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 13:55:34 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_b.h"

int	res_calculator(t_data *data)
{
	data->res_width = data->largeur * T_S;
	data->res_height = data->hauteur * T_S;
	if (data->largeur > 60)
	{
		ft_printf("Error\n\nMap's width too long : [%d]\n\n", data->largeur);
		return (-1);
	}	
	if (data->hauteur > 31)
	{
		ft_printf("Error\n\nMap's height too high : [%d]\n\n", data->hauteur);
		return (-1);
	}
	return (0);
}

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (data->images[i])
			mlx_destroy_image(data->mlx_ptr, data->images[i]);
		i++;
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free(data->map);
	exit(1);
}

void	sprite_errors(char c, t_data *data, int id)
{
	int	i;

	i = 0;
	ft_printf("\n\nError\n\n%c sprite doesn't load\n\n", c);
	while (i < id)
	{
		if (data->images[i])
			mlx_destroy_image(data->mlx_ptr, data->images[i]);
		i++;
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free(data->map);
	exit(1);
}

int	load_next_images(t_data *data)
{
	data->images[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/P_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[4] == NULL)
		return (sprite_errors('P', data, 4), 0);
	data->images[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/B_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[5] == NULL)
		return (sprite_errors('B', data, 5), 0);
	data->images[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"bonus/assets/M_32.xpm", &(int){T_S}, &(int){T_S});
	if (data->images[6] == NULL)
		return (sprite_errors('M', data, 6), 0);
	return (0);
}

void	mlx_error(t_data *d, int f)
{
	if (f == 1)
	{
		ft_printf("Error\n\nMlx init went wrong\n\n");
		ft_free(d->map);
		exit(1);
	}
	if (f == 2)
	{
		ft_printf("Error\n\nMlx window didn't load\n\n");
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		ft_free(d->map);
		exit(1);
	}
	if (f == 3)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		ft_free(d->map);
		exit(1);
	}
}
