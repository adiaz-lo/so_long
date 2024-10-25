#include "includes/so_long.h"
#include "includes/player.h"
#include <readline/readline.h>

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
	int lines;


	mlx_player->map = malloc(sizeof(t_map));
	mlx_player->map->x = 0;
	mlx_player->map->y = 0;
	mlx_player->map->map = malloc(lines  * sizeof(char *) + 1);
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

void	malloc_map(int length, int rows, t_mlx_player *mlx_player)
{
	int	i;
	
	i = 0;
	while (i < rows)
	{
		mlx_player->map->map[i] = malloc(((length + 1) * sizeof(char)));
		i++;
	}
}

int	read_map(t_mlx_player *mlx_player)
{
	int		rows;
	int		map_fd;
	char	*line;
	int		char_nu;
	int		length;
	
	map_fd = open("minimap.ber", O_RDONLY);
	if (map_fd == -1)
		return (1);
	printf("Map fd is: %i %s %i\n", map_fd, __FILE__, __LINE__);
	line = get_next_line(map_fd);
	//length = ft_strlen(*(mlx_player->map->map));
	length = ft_strlen(line);
	malloc_map(length, 42, mlx_player);
	while (line)
	{
		line = get_next_line(map_fd);
		rows++;
	}
	close(map_fd);
	mlx_player->map->map = malloc((rows + 1) * sizeof(char *));
	map_fd = open("minimap.ber", O_RDONLY);
	if (map_fd == -1)
		return (1);
	printf("Map fd is: %i %s %i\n", map_fd, __FILE__, __LINE__);
	line = get_next_line(map_fd);
	char_nu = 0;
	while (line)
	{
		mlx_player->map->map[rows][char_nu];
		get_next_line(map_fd);
		char_nu++;
	}
	close(map_fd);
	
	printf("Debugging Map Reading ---------- %s:%i\n", __FILE__, __LINE__);
	//ft_printf("Debugging Map Reading ---------- %s:%i\n", __FILE__, __LINE__);
//		return (NULL);
	//printf("Debugging Map Reading ---------- %s:%i\n", __FILE__, __LINE__);
	printf("Debugging Map Reading ---------- %s:%i\n", __FILE__, __LINE__);
	while (mlx_player->map->map && *(mlx_player->map->map))
	{
		printf("Debugging Map Reading ---------- %s:%i\n", __FILE__, __LINE__);
		*(mlx_player->map->map) = get_next_line(map_fd);
		printf("Debugging Map Reading ---------- %s %s:%i\n", *(mlx_player->map->map), __FILE__, __LINE__);
		rows++;
		//free(map);
		mlx_player->map->map++;
	}
	*(mlx_player->map->map) = NULL;
	return (rows);
}

void	paint_map(t_mlx_player *mlx_player)
{
	int	index;
	int	row;
	int	length;

	row = 0;
	length = ft_strlen(*(mlx_player->map->map));
//	malloc_map(length, 15, mlx_player);
	printf("Debugging value of length is: %i ---------- %s:%i\n", length, __FILE__, __LINE__);
	while (row < 2)
	{
		index = 0;
		while (index < length)
		{
			printf("Debugging map painting is: %i ---------- %s:%i\n", length, __FILE__, __LINE__);
			if(*(mlx_player->map->map[index]) == 0)
				mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x + (index * TILE_WIDTH), mlx_player->map->y + (row * TILE_HEIGHT));
			else if (*(mlx_player->map->map[index]) == 1)
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
	//int		map[] = {1, 0, 1, 1, 0, 1, 0, 1};
	int		map_fd;
	int i, j;

//	int length = 8;
	mlx_player = malloc(sizeof(t_mlx_player));
	mlx_player->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", true);
	mlx_player->player = init_player(mlx_player);
	mlx_player->map = init_map(mlx_player);

	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x, mlx_player->map->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x+FLOOR_WIDTH, mlx_player->map->y);
//	open_map(map_fd);
	//map_fd = open("minimap.ber", O_RDONLY);
	read_map(mlx_player);
	if (mlx_player->map->map == NULL)
		return (printf("Could not read map\n"));
	i = 0;
	while (mlx_player->map->map[i])
	{
		j = 0;
		while (mlx_player->map->map[i][j])
		{
			printf("%c", mlx_player->map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	paint_map(mlx_player);
	
	mlx_key_hook(mlx_player->mlx, &my_keyhook, mlx_player);
	swap_layers(mlx_player);

	mlx_loop(mlx_player->mlx);
	destroy_player(mlx_player);
	free(mlx_player->player);
	mlx_terminate(mlx_player->mlx);
	close(map_fd);

	return(0);
}
