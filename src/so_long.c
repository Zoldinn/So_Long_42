/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:19 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 18:46:10 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);

	data.win = mlx_new_window(data.mlx, 1920, 1080, "So_Long");
	if (data.win == NULL)
		return (free(data.mlx), EXIT_FAILURE);

	// fonction charger toutes mes images

	// gestion des touches
	mlx_key_hook(data.win, &ft_escape_to_quit, &data);
	
	// affichage
	
	mlx_loop(data.mlx);

	// fonction pour detruires toutes mes imgs

	mlx_destroy_display(data.mlx);
	return (free(data.mlx), EXIT_SUCCESS);
}
