// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
//#include "MLX42/MLX42.h"
#include "../include/so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 1000
#define HEIGHT 1000

rectangle_t rtg;
mlx_t* mlx;
mlx_image_t* canvas;

typedef struct position
{
	int32_t	x;
	int32_t	y;
}	position_t;

position_t pos;

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static	void	ft_paint_pixel(int x, int y, int32_t color)
{
	mlx_put_pixel(canvas, x, y, color);
}

/**
 * Initializes the rectangle struct to NULL
 */
void	ft_initialize_struct(rectangle_t *rtg)
{
	rtg->width = 0;
	rtg->height = 0;
	rtg->x = 0;
	rtg->y = 0;
	rtg->color.red = 0;
	rtg->color.green = 0;
	rtg->color.blue = 0;
	rtg->color.alpha = 0;
}

/**
 *
 */
mlx_image_t	*ft_create_image(mlx_t *mlx)
{
	mlx_image_t *img;

	img = mlx_new_image(mlx, 20, 100);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	return (img);
}

//Delete duplicities, delete hardcoding & add refresh screen function

void	ft_paint_rectangle(rectangle_t *rtg)
{
	int	x2;
	int	y2;
	int	color_i;

	rtg->x = 0;
	rtg->y = 0;
	if (rtg->width == 0)
		rtg->width = 20;
	if (rtg->height == 0)
		rtg->height = 100;
	// rtg->color.red = 20;
	// rtg->color.green = 80;
	// rtg->color.blue = 74;
	// rtg->color.alpha = 127;
	// color_i = get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha);
	if (rtg->color.red == 0)
		rtg->color.red = 20;
	if (rtg->color.green == 0)
		rtg->color.green = 80;
	if (rtg->color.blue == 0)
		rtg->color.blue = 74;
	if (rtg->color.alpha == 0)
		rtg->color.alpha = 127;
	color_i = get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha);
	y2 = pos.y;
	while (y2 < rtg->height + pos.y)
	{
		x2 = pos.x;
		while (x2 < rtg->width + pos.x)
		{
			// ft_paint_pixel(x2, y2, color_i);
			//ft_paint_pixel(x2, y2, (color_t *){100, 100, 100, 127});
			ft_paint_pixel(x2, y2, color_i);
			x2++;
		}
		y2++;
	}
}

/**
 * This function does the refresh screen, repaiting everything in the image to black
 */
void	ft_refresh_screen(rectangle_t *rtg)
{
/*	rtg->width = WIDTH;
	rtg->height = HEIGHT;
	rtg->color.red = 0;
	rtg->color.green = 0;
	rtg->color.blue = 0;
	rtg->color.alpha = 127;*/
	ft_paint_rectangle(rtg);
}

void	ft_paint(rectangle_t *img)
{
	ft_paint_rectangle(img);
}

/**
 * Does the render stuff
 */
void	ft_render(mlx_key_data_t keydata, void* param)
{
	rectangle_t *canvas = ((game_t *)param)->canvas;
	rectangle_t *img = ((game_t *)param)->img;
	ft_refresh_screen(canvas);
	ft_paint(img);
//	ft_paint_rectangle(&rtg);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	//	(void)param;
	rectangle_t rtg = *(rectangle_t *)param;
	// if (keydata.key >= MLX_KEY_A && keydata.key <= MLX_KEY_Z && keydata.action == MLX_PRESS)
	// {
	// 	if (keydata.modifier == MLX_SHIFT)
	// 		printf("%c\n", toupper(keydata.key));
	// 	else
	// 	{
	// 		if (keydata.modifier == 0)
	// 			printf("%c\n", tolower(keydata.key));
	// 	}
	// }
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	// If we PRESS the 'D' key, print "Hello".
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		// printf("Checking limits %d\n", pos.x);
		if (pos.x > WIDTH - rtg.width - 1)
		{
			// printf("Error\n");
			// printf("%d\n", rtg.width);
			// printf("%d\n", WIDTH - rtg.width);
			// printf("%p\n", &rtg);
//			ft_refresh_screen(&rtg);
			return ;
		}
//		mlx_delete_image(mlx, img);
//		ft_refresh_screen(&rtg);
//		ft_paint_rectangle(&rtg);
		pos.x += 10;
//		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.x);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.y > HEIGHT - rtg.height - 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.y += 10;
//		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.y);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.x < 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.x -= 10;
//		ft_paint_rectangle(&rtg);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (pos.y < 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.y -= 10;
//		ft_paint_rectangle(&rtg);
	}
	//puts(D);

	/*	// If we RELEASE the 'K' key, print "World".
		if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
	puts("!");*/
}

int32_t	main(void)
{
	//	mlx_t* mlx;
	mlx_image_t* canvas;
	mlx_image_t* img;
	game_t	*game;

	pos.x = 0;
	pos.y = 0;
	// mlx_set_setting(MLX_DECORATED, false);
	// mlx_set_setting(MLX_HEADLESS, true);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Hook", true)))
		return (EXIT_FAILURE);
	canvas = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!canvas || (mlx_image_to_window(mlx, canvas, 0, 0) < 0))
		ft_error();
	img = ft_create_image(mlx);
	game = calloc(1, sizeof(game_t));
	game->canvas = canvas;
	game->img = img;
//	mlx_create_buffers(mlx);
	ft_initialize_struct(&rtg);
	//mlx_key_hook(mlx, &my_keyhook, &rtg);
	mlx_key_hook(mlx, &my_keyhook, game);
	//ft_paint_rectangle(&rtg);
	//	ft_paint_pixel(1010, 500);
	//mlx_loop_hook(mlx, &ft_render, &rtg);
	mlx_loop_hook(mlx, &ft_render, game);
	mlx_loop(mlx);
//	mlx_loop_hook(mlx, &ft_render, &rtg);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
