// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
//#include "MLX42/MLX42.h"
#include "../include/so_long.h"
//#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 1000
#define HEIGHT 1000
#define I_WIDTH 20
#define I_HEIGHT 100

//rectangle_t rtg;
//mlx_t* mlx;
//mlx_image_t* canvas;

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

/*static	void	ft_paint_pixel(int x, int y, int32_t color)
{
	mlx_put_pixel(canvas, x, y, color);
}*/

void	ft_put_pixels_rectangle(rectangle_t *rtg)
{
	int	x;
	int	y;

	y = 0;
	while (y < rtg->size[1])
	{
		x = 0;
		while (x < rtg->size[0])
		{
			// ft_paint_pixel(x2, y2, color_i);
			//ft_paint_pixel(x2, y2, (color_t *){100, 100, 100, 127});
//			mlx_put_pixel(rtg->img, x, y, get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha));
			//mlx_put_pixel(rtg->img, x, y, get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, 1));	Gradient Light Grey Little Rectangle & Darker Light Grey Background
			mlx_put_pixel(rtg->img, x, y, get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha));
			x++;
		}
		y++;
	}
}

/**
 * Initializes the rectangle struct to NULL
 */
int	ft_initialize_struct(game_t **game)
{
	mlx_t* mlx;
	mlx_image_t* canvas_img;
	mlx_image_t* img;
	//int	color_i;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Hook", true)))
		return (EXIT_FAILURE);
	canvas_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!canvas_img)
		ft_error();
	img = mlx_new_image(mlx, I_WIDTH, I_HEIGHT);
	(*game) = calloc(1, sizeof(game_t));
	(*game)->mlx = mlx;
	(*game)->canvas = calloc(1, sizeof(rectangle_t));
	(*game)->canvas->size[0] = WIDTH;
	(*game)->canvas->size[1] = HEIGHT;
	(*game)->canvas->img = canvas_img;
	//(*game)->canvas->color = (color_t){0, 0, 0, 0};
	(*game)->canvas->color = (color_t){0, 0, 0, 255};
/*	(*game)->canvas->color.red = 0;
	(*game)->canvas->color.green = 0;
	(*game)->canvas->color.blue = 0;
	(*game)->canvas->color.alpha = 255;*/
	//color_i = get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha);
	ft_put_pixels_rectangle((*game)->canvas);
	(*game)->img = calloc(1, sizeof(rectangle_t));
	(*game)->img->size[0]= I_WIDTH;
	(*game)->img->size[1] = I_HEIGHT;
	(*game)->img->img = img;
	//(*game)->img->color = (color_t){42, 42, 42, 127};
	//(*game)->img->color = (color_t){0xff, 0xff, 0xff, 0xff};
	(*game)->img->color = (color_t){0x8f, 0xd3, 0xca, 0xff};
/*	(*game)->img->color.red = 255;
	(*game)->img->color.green = 0;
	(*game)->img->color.blue = 0;
	(*game)->img->color.alpha = 255;*/
	ft_put_pixels_rectangle((*game)->img);
	/*rtg->width = 0;
	rtg->height = 0;
	rtg->x = 0;
	rtg->y = 0;
	rtg->color.red = 0;
	rtg->color.green = 0;
	rtg->color.blue = 0;
	rtg->color.alpha = 0;*/
	return (0);
}

/**
 *
 */
/*mlx_image_t	*ft_create_image(mlx_t *mlx)
{
	mlx_image_t *img;

	
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	return (img);
}*/

//Delete duplicities, delete hardcoding & add refresh screen function

void	ft_paint_rectangle(rectangle_t *rtg, mlx_t *mlx, int x, int y)
{
	// Deprecated code for if
	/*rtg->x = 0;
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
		rtg->color.alpha = 127;*/
	//color_i = get_rgba(rtg->color.red, rtg->color.green, rtg->color.blue, rtg->color.alpha);
	mlx_image_to_window(mlx, rtg->img, x, y);
}

/**
 * This function does the refresh screen, repaiting everything in the image to black
 */
void	ft_refresh_screen(rectangle_t *rtg, mlx_t *mlx)
{
/*	rtg->width = WIDTH;
	rtg->height = HEIGHT;
	rtg->color.red = 0;
	rtg->color.green = 0;
	rtg->color.blue = 0;
	rtg->color.alpha = 127;*/
	ft_paint_rectangle(rtg, mlx, 0, 0);
}

void	ft_paint(rectangle_t *img, mlx_t *mlx, game_t *game)
{
//	printf("x coordinate value: %d\n", game->img->x);
//	printf("y coordinate value: %d\n", game->img->y);
	ft_paint_rectangle(img, mlx, game->img->x, game->img->y);
}

/**
 * Does the render stuff
 */
void	ft_render(void* param)
{
	game_t *game = (game_t *)param;

	rectangle_t *canvas = ((game_t *)param)->canvas;
	rectangle_t *img = ((game_t *)param)->img;

	ft_paint(img, ((game_t *)param)->mlx, game);
	ft_refresh_screen(canvas, ((game_t *)param)->mlx);
	usleep(50000);
//	ft_paint_rectangle(&rtg);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	//	(void)param;
	game_t *game = (game_t *)param;
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
		mlx_close_window(game->mlx);
	// If we PRESS the 'D' key, print "Hello".
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		// printf("Checking limits %d\n", pos.x);
		if (game->img->x > (game->canvas->size[0] - game->img->size[0]) - 10)
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
//		pos.x += 10;
		game->img->x += 10;
		//game->img->img->instances[0].x += 10;
//		ft_paint_rectangle(&rtg);
		//printf("%d\n", pos.x);
		printf("x coordinate value: %d\n", game->img->x);
		printf("Canvas Width: %d\n", game->canvas->size[0]);
		printf("Image Width: %d\n", game->img->size[0]);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (game->img->y > (game->canvas->size[1] - game->img->size[1]) - 10)
			return ;
//		mlx_delete_image(mlx, img);
//		pos.y += 10;
		game->img->y += 10;
//		ft_paint_rectangle(&rtg);
//		printf("%d\n", pos.y);
		printf("%d\n", game->img->y);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (game->img->x < 10)
			return ;
//		mlx_delete_image(mlx, img);
		//pos.x -= 10;
		game->img->x -= 10;
//		ft_paint_rectangle(&rtg);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (game->img->y < 10)
			return ;
//		mlx_delete_image(mlx, img);
//		pos.y -= 10;
		game->img->y -= 10;
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
	game_t	*game;

	pos.x = 0;
	pos.y = 0;
	game = NULL;
	// mlx_set_setting(MLX_DECORATED, false);
	// mlx_set_setting(MLX_HEADLESS, true);
	// mlx_set_setting(MLX_FULLSCREEN, true);
//	mlx_create_buffers(mlx);
	if (ft_initialize_struct(&game))
		return (EXIT_FAILURE);
	//mlx_key_hook(mlx, &my_keyhook, &rtg);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	//printf("x coordinate value: %d\n", game->img->img->instances[0].x);
	//ft_paint_rectangle(&rtg);
	//	ft_paint_pixel(1010, 500);
	//mlx_loop_hook(mlx, &ft_render, &rtg);
	mlx_loop_hook(game->mlx, &ft_render, game);
	mlx_loop(game->mlx);
//	mlx_loop_hook(mlx, &ft_render, &rtg);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
