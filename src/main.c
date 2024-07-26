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

static	void	ft_paint_pixel(int x, int y)
{
	mlx_put_pixel(img, x, y, 0xFFFFFFFF);
}

void	ft_paint_rectangle(rectangle_t *rtg)
{
	int	x2;
	int	y2;

	rtg->x = 0;
	rtg->y = 0;
	rtg->width = 25;
	rtg->height = 100;
	y2 = pos.y;
	while (y2 < rtg->height + pos.y)
	{
		x2 = pos.x;
		while (x2 < rtg->width + pos.x)
		{
			ft_paint_pixel(x2, y2);
			x2++;
		}
		y2++;
	}

}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
//	(void)param;
	rectangle_t rtg = *(rectangle_t *)param;
	if (keydata.key >= 65 && keydata.key <= 90 && keydata.action == MLX_PRESS)
	{
		if (keydata.modifier == MLX_SHIFT)
			printf("%c\n", toupper(keydata.key));
		else
		{
			if (keydata.modifier == 0)
				printf("%c\n", tolower(keydata.key));
		}
	}
	// If we PRESS the 'D' key, print "Hello".
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		printf("Checking limits %d\n", pos.x);
		/*if (pos.x > WIDTH - rtg.width)
		{
			printf("Error\n");
			printf("%d\n", rtg.width);
			printf("%d\n", WIDTH - rtg.width);
			printf("%p\n", &rtg);
			return ;
		}*/
		pos.x += 10;
		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.x);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.y > HEIGHT - rtg.height)
			return ;
		pos.y += 10;
		ft_paint_rectangle(&rtg);
		printf("%d\n", pos.y);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.x < 10)
			return ;
		pos.x -= 10;
		ft_paint_rectangle(&rtg);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (pos.y < 10)
			return ;
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

int32_t	main(void)
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
	mlx_key_hook(mlx, &my_keyhook, &rtg);
	ft_paint_rectangle(&rtg);
	ft_paint_pixel(1010, 500);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
