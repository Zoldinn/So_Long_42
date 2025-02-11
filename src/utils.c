/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:47:56 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/11 14:03:44 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//* pas destroy window --> deja avec la fonction pour ESCAPE
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