/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:33:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/19 18:35:14 by lefoffan         ###   ########.fr       */
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
	game->sprites[0] = ft_sprite_init(game, PATH_GROUND);
	game->sprites[1] = ft_sprite_init(game, PATH_WALL);
	game->sprites[2] = ft_sprite_init(game, PATH_DOOR1);
	game->sprites[3] = ft_sprite_init(game, PATH_DOOR2);
	game->sprites[4] = ft_sprite_init(game, PATH_POTION);
	game->sprites[5] = ft_sprite_init(game, PATH_PLAYER);
}

t_map	ft_load_map(int fdmap)
{
	t_map	datamap;
	char	*line;

	datamap.map = NULL;
	line = get_next_line(fdmap);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		datamap.map = ft_add_line(datamap.map, line);
		line = get_next_line(fdmap);
	}
	ft_get_datamap(&datamap);
	return (datamap);
}
