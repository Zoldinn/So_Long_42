#include "../includes/so_long.h"

/**========================================================================
 ** endian == 0 --> LE -> MSB a droite, LSB a gauche
 ** endian != 0 --> BE -> MSB a gauche, LSB a droite
 ** decalage de bit pour le cas ou on a pas la meme taille de int (Selon le pc)
 *========================================================================**/
void	img_put_pixel(t_imgs *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	pixel = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
	i = img->bpp - 8;
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - i - 8)) & 0xFF;
		i -= 8;
	}
}

void	render_rect(t_imgs *img, t_rect rect)
{
	int	curx;
	int	cury;

	cury = rect.y;
	while (cury < rect.y + rect.height)
	{
		curx = rect.x;
		while (curx < rect.x + rect.width)
			img_put_pixel(img, curx++, cury, rect.color);
		++cury;
	}
}

void	render_background(t_imgs *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			img_put_pixel(img, x++, y, color);
		++y;
	}
}

/**==============================================
 **                  Affichage
 *=============================================**/
int	render(t_data *data)
{
	if (data->win == NULL)
		return (FAIL);
	render_background(&data->img, WHITE);
	render_rect(&data->img, (t_rect){WIDTH - 100, HEIGHT - 100, 100, 100, GREEN});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED});
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (OK);
}