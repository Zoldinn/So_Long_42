/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:24 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 16:50:08 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render(t_data *data)
{
	t_sprite	sprite;

	if (data->win == NULL)
		return (FAIL);

	sprite.path = "sprites/wall_front_view2.xpm";
	sprite.img = mlx_xpm_file_to_image(data->mlx, sprite.path, &sprite.width, &sprite.height);

	mlx_put_image_to_window(data->mlx, data->win, sprite.img, WIDTH/2, HEIGHT/2);
	
	return (OK);
}

