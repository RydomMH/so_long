/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:16:38 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/20 17:10:39 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strrchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return (i + 1);
		i--;
	}
	return (0);
}

void	fd_error(void)
{
	ft_printf("Error\n\nFD didn't open :/\n\n");
}

int	is_map_empty(int *fd, char *name)
{
	char	*buffer;
	ssize_t	r_bytes;

	r_bytes = 0;
	buffer = malloc(sizeof(char) * 10);
	if (buffer == NULL)
		return (-1);
	r_bytes = read(*fd, buffer, 10);
	if (r_bytes == 0)
	{
		ft_printf("Error\n\nEmpty map");
		close(*fd);
		return (free(buffer), buffer = NULL, -1);
	}
	close(*fd);
	*fd = open(name, O_RDWR);
	if (*fd == -1)
		return (fd_error(), free(buffer), buffer = NULL, -1);
	return (free(buffer), buffer = NULL, 0);
}

int	verif_extension(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (ft_printf("Error\n\nNo map to open\n\n"), -1);
	i = ft_strrchr(str, '/');
	if (str[i] == '.')
		return (ft_printf("Error\n\nInvalid map name\n\n"), -1);
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (ft_printf("Error\n\nNo extension\n\n"), -1);
	if (str[i + 1] != 'b' || str[i + 2] != 'e' || str[i + 3] != 'r' || str[i
			+ 4] != '\0')
		return (ft_printf("Error\n\nInvalid extenstion name\n\n"), -1);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = 0;
	data.map = NULL;
	data.nb_coin = 0;
	data.total_coin = 0;
	data.hauteur = 0;
	data.largeur = 0;
	if (ac < 2)
		return (ft_printf("Error\n\nMissing ARG\n\n"), -1);
	if (verif_extension(av[1]) == -1)
		return (-1);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (fd_error(), -1);
	if (is_map_empty(&fd, av[1]) == -1)
		return (-1);
	data.map = is_map_valid(fd, &data);
	close(fd);
	if (data.map == NULL || data.map[0][0] == '\0')
		return (ft_free(data.map), data.map = NULL, -1);
	ft_printf("ENJOY THE GAME :D\n\n");
	launch_game(&data);
}
