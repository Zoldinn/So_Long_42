#include "so_long.h"



int	key_esc(int key, t_data *data)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == (void*) 0)
		return (EXIT_FAILURE);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "test");
	if (data.win == (void*) 0)
		return (EXIT_FAILURE);
	mlx_key_hook(data.win, &key_esc, &data);
	mlx_loop(data.mlx);
	return (0);
}