/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:47:56 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/19 18:23:26 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	if (map)
		free(map);
}

//* Kind of realloc to add a new line to map (char**)
char	**ft_add_line(char **old_map, char *new_line)
{
	char	**new_map;
	int		count_line;
	int		i;

	if (!new_line)
		return (NULL);
	if (!old_map)
	{
		new_map = malloc(sizeof(char **) * 2);
		if (!new_map)
			return (free(new_line), NULL);
		return (new_map[0] = new_line, new_map[1] = NULL, new_map);
	}
	count_line = 0;
	while (old_map[count_line] != NULL)
		count_line++;
	new_map = malloc(sizeof(char **) * (count_line + 2));
	if (!new_map)
		return (free(new_line), NULL);
	i = -1;
	while (old_map[++i])
		new_map[i] = ft_strdup(old_map[i]);
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	return (ft_clear_map(old_map), new_map);
}

// to move player
void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

//* Get the player's pos, count of potions, map size
void	ft_get_datamap(t_map *datamap)
{
	if (!datamap->map)
		return ;
	datamap->potions_count = 0;
	datamap->height = 0;
	while (datamap->map[datamap->height])
	{
		datamap->width = 0;
		while (datamap->map[datamap->height][datamap->width])
		{
			if (datamap->map[datamap->height][datamap->width] == 'C')
				datamap->potions_count += 1;
			if (datamap->map[datamap->height][datamap->width] == 'P')
			{
				datamap->player.x = datamap->width;
				datamap->player.y = datamap->height;
			}
			datamap->width++;
		}
		datamap->height++;
	}
}

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
	row = -1;
	while (map[++row])
		cpy[row] = ft_strdup(map[row]);
	cpy[row] = NULL;
	return (cpy);
}
