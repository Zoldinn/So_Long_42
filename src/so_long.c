/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/19 18:34:30 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_end_game(t_game *game)
{
	if (game->GROUND.img)
		mlx_destroy_image(game->mlx, game->sprites[0].img);
	if (game->WALL.img)
		mlx_destroy_image(game->mlx, game->sprites[1].img);
	if (game->DOOR_OPEN.img)
		mlx_destroy_image(game->mlx, game->sprites[2].img);
	if (game->DOOR_CLOSE.img)
		mlx_destroy_image(game->mlx, game->sprites[3].img);
	if (game->POTION.img)
		mlx_destroy_image(game->mlx, game->sprites[4].img);
	if (game->PLAYER.img)
		mlx_destroy_image(game->mlx, game->sprites[5].img);
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
		return (ft_perror("Enter the path of the map only\n"), FAIL);
	game.datamap = ft_load_map(open(av[1], O_RDONLY));
	if (ft_check_map(&game.datamap) == FAIL)
		return (ft_clear_map(game.datamap.map), FAIL);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (ft_perror("Error : mlx init\n"), EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, game.datamap.width * SPRITE_WIDTH,
			game.datamap.height * SPRITE_HEIGHT, "So_Long");
	if (game.win == NULL)
		return (free(game.mlx), ft_perror("Error : window init"), EXIT_FAILURE);
	game.nb_moves = 0;
	ft_load_sprites(&game);
	mlx_loop_hook(game.mlx, &ft_render, &game);
	mlx_key_hook(game.win, &ft_move, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_escape_to_quit, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &ft_end_game, &game);
	mlx_loop(game.mlx);
	ft_end_game(&game);
}
