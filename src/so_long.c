/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/18 15:26:50 by lefoffan         ###   ########.fr       */
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
	ft_clear_map(game->datamap.map);
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Enter the path of the map only\n", 31), FAIL);

	game.datamap = ft_load_map(open(av[1], O_RDONLY));
	if (ft_check_map(&game.datamap) == FAIL)
		return (ft_clear_map(game.datamap.map), FAIL);

	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, game.datamap.width * 32,
		game.datamap.height * 32, "So_Long");
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
