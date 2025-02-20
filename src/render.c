/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:24 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/20 10:34:33 by lefoffan         ###   ########.fr       */
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
	while (game->datamap.map[row])
	{
		col = 0;
		while (game->datamap.map[row][col])
		{
			if (game->datamap.map[row][col] == where)
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
	ft_put_image(game, '1', game->sprites[1].img);
	ft_put_image(game, '0', game->sprites[0].img);
	ft_put_image(game, 'P', game->sprites[5].img);
	ft_put_image(game, 'C', game->sprites[4].img);
	if (game->datamap.potions_count != 0)
		ft_put_image(game, 'E', game->sprites[3].img);
	else
		ft_put_image(game, 'E', game->sprites[2].img);
	return (OK);
}
