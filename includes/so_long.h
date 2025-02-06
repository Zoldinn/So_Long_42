/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:33:58 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/06 17:14:16 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

//* more readable
# define FAIL		1
# define OK			0

//* colors
# define RED		0xFF0000
# define GREEN		0xFF00
# define BLUE		0xFF

//* window
# define WINDOW_WIDTH		1920
# define WINDOW_HEIGHT		1080

//* keys code
# define ESCAPE		65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

void	ft_error(t_data *data);
int		key_esc(int key, t_data *data);
int		render(t_data *data);

#endif