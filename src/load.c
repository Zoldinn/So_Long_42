/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:33:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/18 15:33:09 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	ft_sprite_init(t_game *game, char *path)
{
	t_sprite	sprite;

	sprite.path = path;
	sprite.img = mlx_xpm_file_to_image(game->mlx, sprite.path,
										&sprite.width, &sprite.height);
	if (sprite.img == NULL)
	{
		perror("Error loading image\n");
		ft_end_game(game);
	}
	sprite.addr = mlx_get_data_addr(sprite.img,
								&sprite.bpp, &sprite.size_line, &sprite.endian);
	if (sprite.addr == NULL)
	{
		perror("Error loading image\n");
		ft_end_game(game);
	}
	return (sprite);
}

void	ft_load_sprites(t_game *game)
{
	game->GROUND = ft_sprite_init(game, PATH_GROUND);
	game->WALL = ft_sprite_init(game, PATH_WALL);
	game->DOOR_OPEN = ft_sprite_init(game, PATH_DOOR1);
	game->DOOR_CLOSE = ft_sprite_init(game, PATH_DOOR2);
	game->POTION = ft_sprite_init(game, PATH_POTION);
	game->PLAYER = ft_sprite_init(game, PATH_PLAYER);
}

t_map	ft_load_map(int fdmap)
{
	t_map	datamap;
	char	*line;
	char	**map;

	datamap.map = NULL;
	map = datamap.map;
	line = get_next_line(fdmap);
	while (line)
	{
		map = ft_add_line(map, line);
		line = get_next_line(fdmap);
	}
	ft_get_datamap(&datamap);
	map[datamap.height - 1][datamap.width] = '\0';
	return (datamap);
}

