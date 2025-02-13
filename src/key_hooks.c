/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:27 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/13 18:11:42 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_escape_to_quit(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		ft_end_game(game);
	}
	return (OK);
}

int	ft_move(int key, t_game *game)
{
	t_pos	pos_player;
	char	**map;

	game->map_data.player = ft_get_pos(&game->map_data, 'P');
	pos_player = game->map_data.player;
	map = game->map_data.map;
	if (key == KEY_UP && map[pos_player.y - 1][pos_player.x] != '1')
		ft_swap(&map[pos_player.y][pos_player.x],
				&map[pos_player.y - 1][pos_player.x]);
	if (key == KEY_DOWN && map[pos_player.y + 1][pos_player.x] != '1')
		ft_swap(&map[pos_player.y][pos_player.x],
				&map[pos_player.y + 1][pos_player.x]);
	if (key == KEY_LEFT && map[pos_player.y][pos_player.x - 1] != '1')
		ft_swap(&map[pos_player.y][pos_player.x],
				&map[pos_player.y][pos_player.x - 1]);
	if (key == KEY_RIGHT && map[pos_player.y][pos_player.x + 1] != '1')
		ft_swap(&map[pos_player.y][pos_player.x],
				&map[pos_player.y][pos_player.x + 1]);
	return (OK);
}
