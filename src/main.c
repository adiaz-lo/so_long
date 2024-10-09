#include "includes/so_long.h"
#include "includes/player.h"

t_player	*init_player(t_mlx_player *mlx_player)
{
	mlx_player->player = malloc(sizeof(t_player));
	mlx_player->player->x = 0;
	mlx_player->player->y = 0;
	mlx_player->player->texture = mlx_load_png("tuxy_resized.png");
	mlx_player->player->image_tuxy = mlx_texture_to_image(mlx_player->mlx, mlx_player->player->texture);
	return (mlx_player->player);
}

t_map	*init_map(t_mlx_player *mlx_player)
{
	mlx_player->map = malloc(sizeof(t_map));
	mlx_player->map->x = 0;
	mlx_player->map->y = 0;
	mlx_player->map->texture_floor = mlx_load_png("floor.png");
	mlx_player->map->image_floor = mlx_texture_to_image(mlx_player->mlx, mlx_player->map->texture_floor);
	mlx_player->map->texture_wall = mlx_load_png("wall_final.png");
	mlx_player->map->image_wall = mlx_texture_to_image(mlx_player->mlx, mlx_player->map->texture_wall);
	return (mlx_player->map);
}

void	destroy_player(t_mlx_player *mlx_player)
{
	printf("Testing the limits %s %i\n", __FILE__, __LINE__);
	mlx_delete_image(mlx_player->mlx, mlx_player->player->image_tuxy);
	printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//	mlx_delete_texture(mlx_player->player->texture);
	printf("Testing the limits %s %i\n", __FILE__, __LINE__);
	printf("%s:%i\n", __FILE__, __LINE__);
	printf("%s:%i\n", __FILE__, __LINE__);
	//free(mlx_player);
	//free(mlx_player);
}

void	paint_map(int *map, t_mlx_player *mlx_player, int length)
{
	int	index;
	int	row;

	row = 0;
	printf("Value of length is: %i ---------- %s:%i\n", length, __FILE__, __LINE__);
	while (row < 2)
	{
		index = 0;
		while (index < length)
		{
			if(map[index] == 0)
				mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x + (index * TILE_WIDTH), mlx_player->map->y + (row * TILE_HEIGHT));
			else if (map[index] == 1)
				mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_wall, mlx_player->map->x + (index * TILE_WIDTH), mlx_player->map->y + (row * TILE_HEIGHT));
	printf("Value of y is: %i ---------- %s:%i\n", mlx_player->map->y + (row * TILE_HEIGHT), __FILE__, __LINE__);
			if (mlx_player->player->image_tuxy->instances[17].x > 120)
			{
				printf("Hola tuxy invisible %s %i\n", __FILE__, __LINE__);
				mlx_set_instance_depth(mlx_player->player->image_tuxy->instances, 0);
			}
			index++;
		}
	printf("Value of y is: %i ---------- %s:%i\n", mlx_player->map->y + (row * TILE_HEIGHT), __FILE__, __LINE__);
//	printf("Value of row is: %i ---------- %s:%i\n", row, __FILE__, __LINE__);
		row++;
	}
}
void	swap_layers(t_mlx_player *mlx_player)
{
	mlx_set_instance_depth(mlx_player->player->image_tuxy->instances, 17);
}

void	move_player_right(t_mlx_player *mlx_player)
{
	mlx_player->player->image_tuxy->instances[0].x += 10;
}

void	move_player_left(t_mlx_player *mlx_player)
{
	mlx_player->player->image_tuxy->instances[0].x -= 10;
}

void	move_player_down(t_mlx_player *mlx_player)
{
	mlx_player->player->image_tuxy->instances[0].y += 10;
}

void	move_player_up(t_mlx_player *mlx_player)
{
	mlx_player->player->image_tuxy->instances[0].y -= 10;
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	printf("Testing the y down limits\n");
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
		printf("Testing the limits\n");
		if ((mlx_player->player->y + mlx_player->player->image_tuxy->height) > mlx_player->mlx->height)
			return ;
		printf("Testing the limits\n");
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
	t_mlx_player	*mlx_player;
	int		map[] = {1, 0, 1, 1, 0, 1, 0, 1};

	int length = 8;
	mlx_player = malloc(sizeof(t_mlx_player));
	mlx_player->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", true);
	mlx_player->player = init_player(mlx_player);
	mlx_player->map = init_map(mlx_player);

	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x, mlx_player->map->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x+FLOOR_WIDTH, mlx_player->map->y);
	paint_map(map, mlx_player, length);
	mlx_key_hook(mlx_player->mlx, &my_keyhook, mlx_player);
	swap_layers(mlx_player);

	mlx_loop(mlx_player->mlx);
	destroy_player(mlx_player);
	free(mlx_player->player);
	mlx_terminate(mlx_player->mlx);

	return(0);
}
