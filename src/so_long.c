/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/13 17:51:40 by lefoffan         ###   ########.fr       */
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
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Enter the path of the map only\n", 31), FAIL);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, 1920, 1080, "So_Long");
	if (game.win == NULL)
		return (free(game.mlx), EXIT_FAILURE);

	game.map_data = ft_load_map(open(av[1], O_RDONLY));
	ft_load_sprites(&game);
	mlx_loop_hook(game.mlx, &ft_render, &game);

	mlx_key_hook(game.win, &ft_move, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_escape_to_quit, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &ft_end_game, &game);

	mlx_loop(game.mlx);
	ft_end_game(&game);
}
