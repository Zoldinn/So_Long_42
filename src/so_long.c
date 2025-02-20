/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/20 18:44:26 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return fd if path ok
int	ft_check_path(char *path)
{
	int	fd;

	if (ft_strnstr(path, ".ber", ft_strlen(path)) == NULL)
		return (ft_perror("no .ber\n"), FAIL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (close(fd), FAIL);
	if (read(fd, NULL, 0) == -1)
		return (ft_perror("Wrong file\n"), FAIL);
	return (fd);
}

/**==============================================
 * 			Check si la map est :
 * 1. Rectangulaire.
 * 2. Entourée de murs.
 * 3. A un seul joueur.
 * 4. A une seule sortie.
 * 5. S'il y a, au moins une potion.
 * 6. Si les potions sont accessibles.
 *=============================================**/
int	ft_check_map(t_map *datamap)
{
	t_map	cpy;

	if (!datamap || !datamap->map)
		return (ft_perror("No map\n"), FAIL);
	if (ft_is_map_rect(datamap) == FAIL || ft_is_border_wall(datamap) == FAIL)
		return (FAIL);
	if (ft_count(datamap->map, 'C') <= 0 || ft_count(datamap->map, 'P') != 1
		|| ft_count(datamap->map, 'E') != 1)
		return (ft_perror("There's not the good count (P, E or C)\n"), FAIL);
	if (ft_check_another(datamap->map) == FAIL)
		return (ft_perror("Must have only P, C, E, 1 or 0 on map\n"), FAIL);
	cpy.height = datamap->height;
	cpy.width = datamap->width;
	cpy.map = ft_copy_map(datamap->map);
	ft_flood_fill(&cpy, datamap->player.y, datamap->player.x);
	if (ft_count(cpy.map, 'C') != 0)
		return (ft_clear_map(cpy.map), ft_perror("Flood fill\n"), FAIL);
	return (ft_clear_map(cpy.map), OK);
}

int	ft_end_game(t_game *game)
{
	if (game->sprites[0].img)
		mlx_destroy_image(game->mlx, game->sprites[0].img);
	if (game->sprites[1].img)
		mlx_destroy_image(game->mlx, game->sprites[1].img);
	if (game->sprites[2].img)
		mlx_destroy_image(game->mlx, game->sprites[2].img);
	if (game->sprites[3].img)
		mlx_destroy_image(game->mlx, game->sprites[3].img);
	if (game->sprites[4].img)
		mlx_destroy_image(game->mlx, game->sprites[4].img);
	if (game->sprites[5].img)
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
	game.datamap = ft_load_map(ft_check_path(av[1]));
	if (game.datamap.map == NULL)
		return (FAIL);
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
