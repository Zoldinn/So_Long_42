/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/17 15:21:17 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_end_game(t_game *game)
{
	if (game->GROUND.img)
		mlx_destroy_image(game->mlx, game->GROUND.img);
	if (game->WALL.img)
		mlx_destroy_image(game->mlx, game->WALL.img);
	if (game->DOOR_OPEN.img)
		mlx_destroy_image(game->mlx, game->DOOR_OPEN.img);
	if (game->DOOR_CLOSE.img)
		mlx_destroy_image(game->mlx, game->DOOR_CLOSE.img);
	if (game->POTION.img)
		mlx_destroy_image(game->mlx, game->POTION.img);
	if (game->PLAYER.img)
		mlx_destroy_image(game->mlx, game->PLAYER.img);
	ft_clear_map(game->map_data.map);
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_get_window_size(t_map *map_data)
{
	map_data->height = 0;
	while (map_data->map[map_data->height])
	{
		map_data->width = 0;
		while (map_data->map[map_data->height][map_data->width])
			map_data->width += 1;
		map_data->height += 1;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Enter the path of the map only\n", 31), FAIL);

	game.map_data = ft_load_map(open(av[1], O_RDONLY));
	ft_get_window_size(&game.map_data);
	if (ft_check_map(&game.map_data) == FAIL)
		ft_end_game(&game);

	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, game.map_data.width * 32,
							game.map_data.height * 32, "So_Long");
	if (game.win == NULL)
		return (free(game.mlx), EXIT_FAILURE);

	ft_load_sprites(&game);
	mlx_loop_hook(game.mlx, &ft_render, &game);

	mlx_key_hook(game.win, &ft_move, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_escape_to_quit, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &ft_end_game, &game);

	mlx_loop(game.mlx);
	ft_end_game(&game);
}
