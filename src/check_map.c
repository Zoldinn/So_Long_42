/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:07 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/17 17:52:32 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_player(t_map *map_data)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = 0;
	while (map_data->map[r])
	{
		c = 0;
		while (map_data->map[r][c])
		{
			if (map_data->map[r][c] == 'P')
				count++;
			c++;
		}
		r++;
	}
	return (count);
}

int	ft_is_map_rect(t_map *map_data)
{
	int	size;
	int	tmp;
	int	i;

	i = 0;
	size = ft_strlen(map_data->map[i]);
	while (map_data->map[++i])
	{
		tmp = size;
		size = ft_strlen(map_data->map[i]);
		if (tmp != size)
			return (FAIL);
	}
	return (OK);
}

int	ft_is_border_wall(t_map *map_data)
{
	int	r;
	int	c;

	r = 0;
	while (map_data->map[r])
	{
		c = 0;
		while (map_data->map[r][c])
		{
			if ((r == 0 || r == map_data->height - 1
				|| c == 0 || c == map_data->width - 1)
				&& map_data->map[r][c] != 1)
				return (FAIL);
			c++;
		}
		r++;
	}
	return (OK);
}

void	ft_flood_fill(t_map *map_data, int row, int col)
{
	if (row < 0 || row > map_data->height || col < 0 || col > map_data->width)
		return ;
	if (map_data->check.cpy_map[row][col] == '1'
		|| map_data->check.cpy_map[row][col] == 'f')
		return ;
	if (map_data->check.cpy_map[row][col] == 'C')
		map_data->check.count_potion++;
	if (map_data->check.cpy_map[row][col] == 'E')
		map_data->check.count_exit = 1;
	map_data->check.cpy_map[row][col] = 'f';
	ft_flood_fill(map_data, row + 1, col);
	ft_flood_fill(map_data, row - 1, col);
	ft_flood_fill(map_data, row, col + 1);
	ft_flood_fill(map_data, row, col - 1);
}

int	ft_check_map(t_map *map_data)
{
	map_data->check.count_potion = 0;
	map_data->check.count_player = 0;
	map_data->check.count_exit = 0;
	map_data->check.cpy_map = ft_copy_map(map_data->map);
	if (ft_is_map_rect(map_data) == FAIL || ft_is_border_wall(map_data) == FAIL
		|| ft_count_player(map_data) != 1)
	{
		ft_clear_map(map_data->check.cpy_map);
		write(2, "\e[31mError by map\e[0m\n", 22);
		return (FAIL);
	}
	ft_flood_fill(map_data, map_data->player.y, map_data->player.x);
	if (map_data->potions_count != map_data->check.count_potion
		|| map_data->check.count_exit == 0)
	{
		ft_clear_map(map_data->check.cpy_map);
		write(2, "\e[31mError by map\e[0m\n", 22);
		return (FAIL);
	}
	return (ft_clear_map(map_data->check.cpy_map), OK);
}
