/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:15:59 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 16:24:22 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "FT_PRINT/ft_printf.h"
# include "PARSING/GNL/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define T_S 32

typedef struct s_flood_fill
{
	int		nb_coin;
	int		exit_found;
}			t_flood_fill;
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		total_coin;
	int		nb_coin;
	void	*images[5];
	int		largeur;
	int		hauteur;
	int		pas;
	int		res_width;
	int		res_height;
}			t_data;
char		**is_map_valid(int fd, t_data *data);
char		**stock_map(int largeur, int hauteur, int fd, char *map_name);
int			ft_strlenmap(char *str);
int			verif_extension(char *str);
int			verif_map(char **map, t_data *data);
void		ft_free(char **map);
char		**ft_split(char const *str, char c);
int			verif_contour(char **map, t_data *data);
int			inside_map(char **map, int *coin);
void		inivalue(int *exit, int *i, int *j, int *player);
int			flood_fill(char **map, t_data *data_bis);
void		show_map(char **map);
int			algorithme(char **map, t_flood_fill *data, int Px, int Py);
char		**copy_map(char **map, int ligne);
char		*ft_strdup(const char *s);
void		player_pos(char **map, int *Px, int *Py);
int			verif_backslash_n(char *map);
int			launch_game(t_data *data);
int			handle_input(int keysym, t_data *data);
int			close_window(t_data *data);
int			go_up(int y, int x, t_data *data);
int			go_left(int y, int x, t_data *data);
int			go_down(int y, int x, t_data *data);
int			go_right(int y, int x, t_data *data);
void		draw_map(t_data *data);
void		draw_tile(t_data *data, int x, int y, char tile);
int			load_images(t_data *data);
int			res_calculator(t_data *data);
void		player_win(t_data *data, int y, int x, char c);
int			is_map_empty(int *fd, char *name);
void		sprite_errors(char c, t_data *data, int id);
void		mlx_error(t_data *d, int f);
void		fd_error(void);
int			ft_strrchr(char *s, char c);

#endif