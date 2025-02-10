/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:27 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 19:24:26 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_escape_to_quit(int key, t_data *data)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (OK);
}

// autres mouvement pour le joueur