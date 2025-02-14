/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:24 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/14 11:22:15 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_image(t_game *game, char where, void *sprite)
{
	int	row;
	int	col;

	if (!game->win)
		return ;
	row = 0;
	while (game->map_data.map[row])
	{
		col = 0;
		while (game->map_data.map[row][col])
		{
			if (game->map_data.map[row][col] == where)
				mlx_put_image_to_window(game->mlx, game->win, sprite,
										(col * SPRITE_WIDTH),
										(row * SPRITE_HEIGHT));
			col++;
		}
		row++;
	}
}

int	ft_render(t_game *game)
{
	if (game->win == NULL)
		return (FAIL);
	ft_put_image(game, '1', game->WALL.img);
	ft_put_image(game, '0', game->GROUND.img);
	ft_put_image(game, 'P', game->PLAYER.img);
	ft_put_image(game, 'C', game->POTION.img);
	if (game->map_data.potions_count != 0)
		ft_put_image(game, 'E', game->DOOR_CLOSE.img);
	else
		ft_put_image(game, 'E', game->DOOR_OPEN.img);
	return (OK);
}

