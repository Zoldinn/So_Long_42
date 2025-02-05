/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:33:58 by lefoffan          #+#    #+#             */
/*   Updated: 2025/02/05 17:06:34 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define WIDTH	1920
# define HEIGHT	1080
# define ESCAPE	65307

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_data;


#endif