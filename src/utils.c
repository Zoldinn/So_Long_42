#include "../includes/so_long.h"

/**----------------------------------------------
 * !                  WARNING
 **  Destroy_display apres destroy_window
 **  destroy window ferme la fenettre mais ne coupe
 **  pas avec X11.
 *---------------------------------------------**/
void	ft_error(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx); // 
	if (data->mlx) // 
		free(data->mlx);
	data->mlx = NULL;
	write(2, "\e[31mError\n\e[0m", 15);
	exit(EXIT_FAILURE);
}

/**============================================
 *!             Echap pour quitter
 ** Destroy window avant display
 *=============================================**/
int	key_esc(int key, t_data *data)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
		exit(EXIT_SUCCESS);
	}
	return (OK);
}