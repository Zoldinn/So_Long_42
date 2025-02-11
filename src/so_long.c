/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/11 15:33:12 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fdmap;

	if (ac != 2)
		return (write(2, "Enter the path of the map only\n", 31), FAIL);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, 1920, 1080, "So_Long");
	if (game.win == NULL)
		return (free(game.mlx), EXIT_FAILURE);

	fdmap = open(av[1], O_RDONLY);
	ft_load_map(&game, fdmap);
	int i = 0;
	while (game.map[i])
		ft_printf("%s", game.map[i++]);
	ft_load_sprites(&game);
	ft_render(&game);

	mlx_key_hook(game.win, &ft_escape_to_quit, &game);
	mlx_loop(game.mlx);
	ft_end_game(&game);
}
