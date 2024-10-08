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
mlx_image_t* img;

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
	mlx_put_pixel(img, x, y, color);
}

//Delete duplicities, delete hardcoding & add refresh screen function

void	ft_paint_rectangle(rectangle_t *rtg)
{
	int	x2;
	int	y2;
	int	color_i;

	rtg->x = 0;
	rtg->y = 0;
	rtg->width = 20;
	rtg->height = 100;
	// rtg->color.red = 20;
	// rtg->color.green = 80;
	// rtg->color.blue = 74;
	// rtg->color.alpha = 127;
	// color_i = get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha);
	y2 = pos.y;
	while (y2 < rtg->height + pos.y)
	{
		x2 = pos.x;
		while (x2 < rtg->width + pos.x)
		{
			ft_paint_pixel(x2, y2, color_i);
			x2++;
		}
		y2++;
	}
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
			return ;
		}
//		mlx_delete_image(mlx, img);
		ft_paint_rectangle(&rtg);
		pos.x += 10;
		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.x);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.y > HEIGHT - rtg.height - 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.y += 10;
		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.y);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.x < 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.x -= 10;
		ft_paint_rectangle(&rtg);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (pos.y < 10)
			return ;
//		mlx_delete_image(mlx, img);
		pos.y -= 10;
		ft_paint_rectangle(&rtg);
	}
	//puts(D);

	/*	// If we RELEASE the 'K' key, print "World".
		if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
	puts("!");*/
}

int	main(void)
{
	//	mlx_t* mlx;
	//	mlx_image_t* img;

	pos.x = 0;
	pos.y = 0;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Hook", true)))
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
//	mlx_create_buffers(mlx);
	mlx_key_hook(mlx, &my_keyhook, &rtg);
	ft_paint_rectangle(&rtg);
	//	ft_paint_pixel(1010, 500);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}