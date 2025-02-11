/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:24 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/11 14:58:40 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_render(t_game *game)
{
	if (game->win == NULL)
		return (FAIL);
	mlx_put_image_to_window(game->mlx, game->win,
						game->DOOR_OPEN.img, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(game->mlx, game->win,
						game->PLAYER.img, WIDTH / 2, HEIGHT / 2);
	return (OK);
}

