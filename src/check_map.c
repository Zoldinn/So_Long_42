/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:07 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/14 16:02:54 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_copy_map(char **map)
{
	char	**cpy;
	int		row;

	row = 0;
	while (map[row])
		row++;
	cpy = malloc(sizeof(char **) * ++row);
	if (!cpy)
		return (NULL);
	row = 0;
	while (map[row])
		cpy[row] = ft_strdup(map[row++]);
	map[row] = NULL;
	return (cpy);
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

int	ft_flood_fill(char **map, char start, char limit)
{
	int	row;
}

int	ft_check_map(t_map *map_data)
{
	return (ft_is_map_rect(map_data) & )
}