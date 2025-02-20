/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:07 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/20 17:22:19 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// compte ce qu'on lui demande de compter
int	ft_count(char **map, char what)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == what)
				count++;
			c++;
		}
		r++;
	}
	return (count);
}

// check si la map est rectangulaire
int	ft_is_map_rect(t_map *datamap)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(datamap->map[i]);
	while (datamap->map[++i])
	{
		if (size != ft_strlen(datamap->map[i]))
			return (ft_perror("Map isn't rectangle\n"), FAIL);
	}
	return (OK);
}

// check si la map est entourée de murs
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
					|| c == datamap->width - 1) && datamap->map[r][c] != '1')
				return (ft_perror("Map isn't border by wall\n"), FAIL);
			c++;
		}
		r++;
	}
	return (OK);
}

// Algo pour verifier qu'il existe bien un chemin
void	ft_flood_fill(t_map *cpy, int row, int col)
{
	if (row < 0 || row > cpy->height || col < 0 || col > cpy->width)
		return ;
	if (cpy->map[row][col] == '1' || cpy->map[row][col] == 'f')
		return ;
	if (cpy->map[row][col] == 'E')
		return ;
	cpy->map[row][col] = 'f';
	ft_flood_fill(cpy, row + 1, col);
	ft_flood_fill(cpy, row - 1, col);
	ft_flood_fill(cpy, row, col + 1);
	ft_flood_fill(cpy, row, col - 1);
}

//* check if there's another thing than C, P, E, 1, 0
int	ft_check_another(char **map)
{
	int		r;
	int		c;
	char	a;

	r = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			a = map[r][c];
			if (a == '1' || a == '0' || a == 'P' || a == 'C' || a == 'E')
				c++;
			else
				return (FAIL);
		}
		r++;
	}
	return (OK);
}
