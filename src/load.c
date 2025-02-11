/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:33:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/11 15:31:11 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_load_map(t_game *game, int fdmap)
{
	char	**map;

	map = game->map;
	*map = ft_get_next_line(fdmap);
	if (*map == NULL)
		return (perror("Error loading map"), ft_end_game(game), FAIL);
	while (*map++ != NULL)
		*map = ft_get_next_line(fdmap);
	return (OK);
}

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
