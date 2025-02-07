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

	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img,
						&data.img.bpp, &data.img.size_line, &data.img.endian);

	mlx_key_hook(data.win, &key_esc, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	
	mlx_loop(data.mlx);

	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_display(data.mlx);
	
	return (free(data.mlx), EXIT_SUCCESS);
}
