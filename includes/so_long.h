/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:33:58 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/19 18:35:33 by lefoffan         ###   ########.fr       */
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
//* keys code
# define ESCAPE			65307
# define LEFT			65361
# define RIGHT			65363
# define UP				65362
# define DOWN			65364
# define W				119
# define A				97
# define S				115
# define D				100
//* sprites path
# define PATH_GROUND	"sprites/ground1.xpm"
# define PATH_WALL		"sprites/wall_top_view.xpm"
# define PATH_DOOR1		"sprites/door_open.xpm"
# define PATH_DOOR2		"sprites/door_close.xpm"
# define PATH_POTION	"sprites/potion.xpm"
# define PATH_PLAYER	"sprites/player.xpm"
//* sprites
# define SPRITE_WIDTH	32
# define SPRITE_HEIGHT	32

typedef struct s_check
{
	int		count_potion;
	int		count_player;
	int		count_exit;
	char	**cpy_map;
}		t_check;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_sprite
{
	void	*img;
	char	*path;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_sprite;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_pos	player;
	int		potions_count;
	t_check	check;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		datamap;
	t_sprite	sprites[6];
	int			nb_moves;
}				t_game;

int		ft_escape_to_quit(int key, t_game *game);
int		ft_move(int key, t_game *game);
int		ft_end_game(t_game *game);
int		ft_render(t_game *game);
int		ft_check_map(t_map *datamap);
void	ft_load_sprites(t_game *game);
t_map	ft_load_map(int fdmap);
char	**ft_add_line(char **old_map, char *new_line);
void	ft_swap(char *a, char *b);
void	ft_get_datamap(t_map *datamap);
void	ft_clear_map(char **map);
char	**ft_copy_map(char **map);
int		ft_check_map(t_map *datamap);

#endif