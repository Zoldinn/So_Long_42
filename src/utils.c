#include "../includes/so_long.h"

/**============================================
 **             Echap pour quitter
 *=============================================**/
int	key_esc(int key, t_data *data)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (OK);
}