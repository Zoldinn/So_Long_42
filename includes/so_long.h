/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:33:58 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/07 16:11:39 by lefoffan         ###   ########.fr       */
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
# define FAIL			1
# define OK				0
//* colors
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0xFF00
# define BLUE			0xFF
//* window
# define WIDTH	1920
# define HEIGHT	1080
//* keys code
# define ESCAPE			65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364

typedef struct s_rect
{
	int x;
	int	y;
	int	width;
	int	height;
	int	color;
}		t_rect;

/**===================================================
 * *       t_img
 * * bpp :			bits per pixels
 * * size_line :	bytes per lines
 * * endian :		ordre des bytes
 *==================================================**/
typedef struct s_imgs
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_imgs;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgs	img;
}			t_data;

int		key_esc(int key, t_data *data);
int		render(t_data *data);

#endif