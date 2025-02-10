/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:47:56 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 19:24:47 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**========================================================================
 * ? free les images : ground, wall, door1&2, potion, player
 * ? free la mlx
 * ? destroy display, ...
 *========================================================================**/
int	ft_end_game(t_data *data)
{
	if (GROUND)
		mlx_destroy_image(data->mlx, GROUND->img);
	if (WALL)
		mlx_destroy_image(data->mlx, WALL->img);
	if (DOOR_OPEN)
		mlx_destroy_image(data->mlx, DOOR_OPEN->img);
	if (DOOR_CLOSE)
		mlx_destroy_image(data->mlx, DOOR_CLOSE->img);
	if (POTION)
		mlx_destroy_image(data->mlx, POTION->img);
	if (PLAYER)
		mlx_destroy_image(data->mlx, PLAYER->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}