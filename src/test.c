#include "../includes/so_long.h"

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);

	data.win = mlx_new_window(data.mlx, 1920, 1080, "So_Long");
	if (data.win == NULL)
		ft_error(&data);
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_key_hook(data.win, &key_esc, &data);
	mlx_loop_hook(data.mlx, &render, &data);

	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}