/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:07 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/19 18:05:05 by lefoffan         ###   ########.fr       */
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
			return (ft_perror("\nError rect\n"), FAIL);
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
			if ((r == 0 || r == datamap->height - 1
				|| c == 0 || c == datamap->width - 1)
				&& datamap->map[r][c] != '1')
				return (ft_perror("\nError Border\n"), FAIL);
			c++;
		}
		r++;
	}
	return (OK);
}

// Algo pour verifier qu'il existe bien un chemin
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
	{
		datamap->check.cpy_map[row][col] = 'e';
		return ;
	}
	datamap->check.cpy_map[row][col] = 'f';
	ft_flood_fill(datamap, row + 1, col);
	ft_flood_fill(datamap, row - 1, col);
	ft_flood_fill(datamap, row, col + 1);
	ft_flood_fill(datamap, row, col - 1);
}

/**==============================================
 * 			Check si la map est :
 * 1. Rectangulaire.
 * 2. Entourée de murs.
 * 3. A un seul joueur.
 * 4. A une seule sortie.
 * 5. S'il y a, au moins une potion.
 * 6. Si les potions sont accessibles.
 *=============================================**/
int	ft_check_map(t_map *dtmap)
{
	dtmap->check.count_potion = 0;
	dtmap->check.count_player = 0;
	dtmap->check.count_exit = 0;
	dtmap->check.cpy_map = ft_copy_map(dtmap->map);
	if (ft_is_map_rect(dtmap) == FAIL || ft_is_border_wall(dtmap) == FAIL)
		return (ft_clear_map(dtmap->check.cpy_map), FAIL);
	if (ft_count(dtmap->map, 'P') != 1 || ft_count(dtmap->map, 'E') != 1
		|| ft_count(dtmap->map, 'C') <= 0)
		return (ft_clear_map(dtmap->check.cpy_map), ft_perror("Error\n"), FAIL);
	ft_flood_fill(dtmap, dtmap->player.y, dtmap->player.x);
	if (dtmap->potions_count != dtmap->check.count_potion
		|| ft_count(dtmap->check.cpy_map, 'e') != 1)
	{
		ft_clear_map(dtmap->check.cpy_map);
		return (ft_perror("Error\n"), FAIL);
	}
	return (ft_clear_map(dtmap->check.cpy_map), OK);
}

/*
plusieurs joueurs
plusieurs exit
aucun collectible
porte qui bloque l'acces a des collectibles
*/