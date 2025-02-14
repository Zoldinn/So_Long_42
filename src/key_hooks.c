/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:27 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/14 11:32:30 by lefoffan         ###   ########.fr       */
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

// A function complementary for ft_move
void	ft_whats_dest(t_game *game, char *player, char *dest)
{
	if (*dest != 'C' && *dest != 'E' && *dest != '1')
		ft_swap(player, dest);
	else if (*dest == 'C')
	{
		*player = '0';
		*dest = 'P';
		game->map_data.potions_count -= 1;
	}
	else if (*dest == 'E' && game->map_data.potions_count == 0)
		ft_end_game(game);
}

int	ft_move(int key, t_game *game)
{
	t_pos	pos_player;
	char	**map;

	// game->map_data.player = ft_get_pos(&game->map_data, 'P');
	ft_get_map_data(&game->map_data);
	pos_player = game->map_data.player;
	map = game->map_data.map;
	if (key == KEY_UP && map[pos_player.y - 1][pos_player.x] != '1')
		ft_whats_dest(game, &map[pos_player.y][pos_player.x],
					&map[pos_player.y - 1][pos_player.x]);
	else if (key == KEY_DOWN && map[pos_player.y + 1][pos_player.x] != '1')
		ft_whats_dest(game, &map[pos_player.y][pos_player.x],
				&map[pos_player.y + 1][pos_player.x]);
	else if (key == KEY_LEFT && map[pos_player.y][pos_player.x - 1] != '1')
	ft_whats_dest(game, &map[pos_player.y][pos_player.x],
				&map[pos_player.y][pos_player.x - 1]);
	else if (key == KEY_RIGHT && map[pos_player.y][pos_player.x + 1] != '1')
	ft_whats_dest(game, &map[pos_player.y][pos_player.x],
				&map[pos_player.y][pos_player.x + 1]);
	return (OK);
}
