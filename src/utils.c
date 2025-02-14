/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:47:56 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/14 11:03:50 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

//* Kind of realloc to add a new line to map (char**)
char **ft_add_line(char **old_map, char *new_line)
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

//* Get the player's pos and count of potions
void	ft_get_map_data(t_map *map_data)
{
	int	row;
	int	col;

	map_data->potions_count = 0;
	row = 0;
	while (map_data->map[row])
	{
		col = 0;
		while (map_data->map[row][col])
		{
			if (map_data->map[row][col] == 'C')
				map_data->potions_count += 1;
			if (map_data->map[row][col] == 'P')
			{
				map_data->player.x = col;
				map_data->player.y = row;
			}
			col++;
		}
		row++;
	}
}