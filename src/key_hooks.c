/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:27 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/20 14:32:35 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_escape_to_quit(int key, t_game *game)
{
	if (key == ESCAPE)
		ft_end_game(game);
	return (OK);
}

// To move or do depend on dest
void	ft_dest(t_game *game, char *player, char *dest)
{
	if (*dest != 'C' && *dest != 'E' && *dest != '1')
	{
		ft_swap(player, dest);
		ft_printf("moves : %d\n", ++game->nb_moves);
	}
	else if (*dest == 'C')
	{
		*player = '0';
		*dest = 'P';
		game->datamap.potions_count -= 1;
	}
	else if (*dest == 'E' && game->datamap.potions_count == 0)
		ft_end_game(game);
}

int	ft_move(int key, t_game *game)
{
	t_pos	player;
	char	**map;

	ft_get_datamap(&game->datamap);
	player = game->datamap.player;
	map = game->datamap.map;
	if ((key == W || key == UP) && map[player.y - 1][player.x] != '1')
		ft_dest(game, &map[player.y][player.x], &map[player.y - 1][player.x]);
	else if ((key == S || key == DOWN) && map[player.y + 1][player.x] != '1')
		ft_dest(game, &map[player.y][player.x], &map[player.y + 1][player.x]);
	else if ((key == A || key == LEFT) && map[player.y][player.x - 1] != '1')
		ft_dest(game, &map[player.y][player.x], &map[player.y][player.x - 1]);
	else if ((key == D || key == RIGHT) && map[player.y][player.x + 1] != '1')
		ft_dest(game, &map[player.y][player.x], &map[player.y][player.x + 1]);
	return (OK);
}
