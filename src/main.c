#include "includes/so_long.h"
#include "includes/player.h"

t_player	*init_player(mlx_t *mlx)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->texture = mlx_load_png("tuxy.png");
	player->image_tuxy = mlx_texture_to_image(mlx, player->texture);
	return (player);
}

void	move_player_right(t_player *player)
{
	player->x += 10;

}

void	move_player_left(t_player *player)
{
	player->x -= 10;

}

void	move_player_down(t_player *player)
{
	player->y += 10;

}

void	move_player_up(t_player *player)
{
	player->y -= 10;

}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	//game_t *game = (game_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	// If we PRESS the 'D' key, move the player 10 pxl to the right
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (player->image_tuxy > (player-> - game->img->size[0]) - 10)
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

void	destroy_player(t_player *player, mlx_t *mlx)
{
	mlx_delete_image(mlx, player->image_tuxy);
	mlx_delete_texture(player->texture);
	free(player);
}

int32_t	main(void)
{
	t_player *player;
	t_mlx_player *mlx_player;
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", true);
	player = init_player(mlx);
	mlx_image_to_window(mlx, player->image_tuxy, player->x, player->y);
	mlx_key_hook(player, &my_keyhook, game);

	mlx_loop(mlx);
	destroy_player(player, mlx);
	mlx_terminate(mlx);

	return(0);
}
