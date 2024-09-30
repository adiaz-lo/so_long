#include "includes/so_long.h"
#include "includes/player.h"

t_player	*init_player(t_mlx_player *mlx_player)
{
	mlx_player->player = malloc(sizeof(t_player));
	mlx_player->player->x = 0;
	mlx_player->player->y = 0;
	mlx_player->player->texture = mlx_load_png("tuxy.png");
	mlx_player->player->image_tuxy = mlx_texture_to_image(mlx_player->mlx, mlx_player->player->texture);
	return (mlx_player->player);
}

void	destroy_player(t_mlx_player *mlx_player)
{
	mlx_delete_image(mlx_player->mlx, mlx_player->player->image_tuxy);
	mlx_delete_texture(mlx_player->player->texture);
	free(mlx_player->player);
	//free(mlx_player);
}

void	move_player_right(t_mlx_player *mlx_player)
{
	mlx_player->player->x += 10;
	destroy_player(mlx_player);
}

void	move_player_left(t_mlx_player *mlx_player)
{
	mlx_player->player->x -= 10;
	destroy_player(mlx_player);
}

void	move_player_down(t_mlx_player *mlx_player)
{
	mlx_player->player->y += 10;
	destroy_player(mlx_player);
}

void	move_player_up(t_mlx_player *mlx_player)
{
	mlx_player->player->y -= 10;
	destroy_player(mlx_player);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	printf("Testing the intuition\n");
	t_mlx_player *mlx_player = (t_mlx_player *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx_player->mlx);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if ((mlx_player->player->x + mlx_player->player->image_tuxy->width) > mlx_player->mlx->width)
			return ;
		move_player_right(mlx_player);
		printf("x coordinate value: %d\n", mlx_player->player->x);
		printf("Canvas Width: %d\n", mlx_player->player->x);
		printf("Image Width: %d\n", mlx_player->player->x);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if ((mlx_player->player->y + mlx_player->player->image_tuxy->height) > mlx_player->mlx->height)
			return ;
		move_player_down(mlx_player);
		printf("%d\n", mlx_player->player->y);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{	
		if (mlx_player->player->x)
			return ;
		move_player_left(mlx_player);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (mlx_player->player->y)
			return ;
		move_player_up(mlx_player);
	}
}

int32_t	main(void)
{
	t_mlx_player *mlx_player;
	
	mlx_player = malloc(sizeof(t_mlx_player));
	mlx_player->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", true);
	mlx_player->player = init_player(mlx_player);

	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
	mlx_key_hook(mlx_player->mlx, &my_keyhook, mlx_player);

	mlx_loop(mlx_player->mlx);
	destroy_player(mlx_player);
	mlx_terminate(mlx_player->mlx);

	return(0);
}
