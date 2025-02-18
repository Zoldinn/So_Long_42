/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:07 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:23 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_player(t_map *datamap)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = 0;
	while (datamap->map[r])
	{
		c = 0;
		while (datamap->map[r][c])
		{
			if (datamap->map[r][c] == 'P')
				count++;
			c++;
		}
		r++;
	}
	return (count);
}

int	ft_is_map_rect(t_map *datamap)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(datamap->map[i]);
	ft_printf("Line 1 size = %d\n", size);
	while (datamap->map[++i])
	{
		ft_printf("Line %d size = %d\n", i + 1, ft_strlen(datamap->map[i]));
		if (size != ft_strlen(datamap->map[i]))
			return (ft_printf("\nError rect\n"), FAIL);
	}
	return (OK);
}

int	ft_is_border_wall(t_map *datamap)
{
	int	r;
	int	c;

	r = 0;
	while (datamap->map[r])
	{
		c = 0;
		while (datamap->map[r][c])
		{
			if ((r == 0 || r == datamap->height - 1 || c == 0
				|| c == datamap->width - 1) && datamap->map[r][c] != 1)
				return (ft_printf("\nError Border\n"), FAIL);
			c++;
		}
		r++;
	}
	return (OK);
}

void	ft_flood_fill(t_map *datamap, int row, int col)
{
	if (row < 0 || row > datamap->height || col < 0 || col > datamap->width)
		return ;
	if (datamap->check.cpy_map[row][col] == '1'
		|| datamap->check.cpy_map[row][col] == 'f')
		return ;
	if (datamap->check.cpy_map[row][col] == 'C')
		datamap->check.count_potion++;
	if (datamap->check.cpy_map[row][col] == 'E')
		datamap->check.count_exit = 1;
	datamap->check.cpy_map[row][col] = 'f';
	ft_flood_fill(datamap, row + 1, col);
	ft_flood_fill(datamap, row - 1, col);
	ft_flood_fill(datamap, row, col + 1);
	ft_flood_fill(datamap, row, col - 1);
}

int	ft_check_map(t_map *datamap)
{
	datamap->check.count_potion = 0;
	datamap->check.count_player = 0;
	datamap->check.count_exit = 0;
	datamap->check.cpy_map = ft_copy_map(datamap->map);
	if (ft_count_player(datamap) != 1 || ft_is_map_rect(datamap) == FAIL
		|| ft_is_border_wall(datamap) == FAIL)
	{
		ft_clear_map(datamap->check.cpy_map);
		write(2, "\e[31mError by map\e[0m\n", 22);
		return (FAIL);
	}
	ft_flood_fill(datamap, datamap->player.y, datamap->player.x);
	if (datamap->potions_count != datamap->check.count_potion
		|| datamap->check.count_exit == 0)
	{
		ft_clear_map(datamap->check.cpy_map);
		write(2, "\e[31mError by map (flood fill)\e[0m\n", 22);
		return (FAIL);
	}
	return (ft_clear_map(datamap->check.cpy_map), OK);
}
