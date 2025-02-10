/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:33:58 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/10 19:17:33 by lefoffan         ###   ########.fr       */
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
# define WIDTH			1920
# define HEIGHT			1080
//* keys code
# define ESCAPE			65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
//* sprites path
# define PATH_GROUND	"sprites/ground1.xpm"
# define PATH_WALL		"sprites/wall_top_view.xpm"
# define PATH_DOOR1		"sprites/door_open.xpm"
# define PATH_DOOR2		"sprites/door_close.xpm"
# define PATH_POTION	"sprites/potion.xpm"
# define PATH_PLAYER	"sprites/player.xpm"
//* sprites
# define GROUND			data->sprites[0]
# define WALL			data->sprites[1]
# define DOOR_OPEN		data->sprites[2]
# define DOOR_CLOSE		data->sprites[3]
# define POTION			data->sprites[4]
# define PLAYER			data->sprites[5]

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	char	*path;
	int		width;
	int		height;
}			t_sprite;

//* pas sur du besoin ?
/* typedef struct s_imgs
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_imgs; */

typedef struct s_data
{
	void		*mlx;
	void		*win;
	// t_imgs	img;
	t_sprite	**sprites;
}				t_data;

int	ft_escape_to_quit(int key, t_data *data);
int	ft_end_game(t_data *data);

#endif