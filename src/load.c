/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:33:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 19:24:23 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*ft_sprite_init(t_data *data, char *path)
{
	t_sprite	*sprite;

	sprite->path = path;
	sprite->img = mlx_xpm_file_to_image(data->mlx, sprite->path,
										&sprite->width, &sprite->height);
	if (sprite->img == NULL)
	{
		perror("Error loading image, ernno :\n");
		ft_end_game(data);
	}
	return (sprite);
}

// fonction pour appeler sprite init et load toutes les images.