// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "../include/so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 1024
#define HEIGHT 1024

	mlx_t* mlx;
	mlx_image_t* img;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
/*static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}*/

/*static	void	ft_init_window()
{
	int	width;
	int	height;

	width = 1024;
	height = 1024;
	mlx_t* mlx = mlx_init(width, height, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_put_pixel(img, width/2, height/2, 0xFFFFFFFF);
	ft_paint_pixel(width/2, height/2);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}*/

static	void	ft_paint_pixel(int x, int y)
{
/*	mlx_t* mlx = mlx_init(width, height, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
		*/
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_put_pixel(img, x, y, 0xFFFFFFFF);
//	ft_paint_pixel(width/2, height/2);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
/*	mlx_loop(mlx);
	mlx_terminate(mlx);*/
}

/*static	void	ft_paint_pixel(int x, int y)
{
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	
}*/

static	void	ft_paint_rectangle(rectangle_t rtg)
{
	int	x2;
	int	y2;

	y2 = rtg.y;
	while (y2 < rtg.height + rtg.y)
	{
		x2 = rtg.x;
		while (x2 < rtg.width + rtg.x)
		{
			ft_paint_pixel(x2, y2);
			x2++;
		}
		y2++;
	}
}

int32_t	main(void)
{
	rectangle_t rtg;

	rtg.x = 420;
	rtg.y = 420;
	rtg.width= 42;
	rtg.height= 84;
	mlx = mlx_init(WIDTH, HEIGHT, "Rectangle With Struct", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// MLX allows you to define its core behaviour before startup.
/*	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
*/
	/* Do stuff */

	// Create and display the image.
/*	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
*/
	// Even after the image is being displayed, we can still modify the buffer.
	/*mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	*/
//	ft_init_window();
//	ft_paint_pixel(x, y);
	ft_paint_rectangle(rtg);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
