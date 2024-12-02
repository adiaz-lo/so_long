#include "includes/so_long.h"
#include "includes/player.h"
#include <readline/readline.h>

void	throw_error(char *string_error)
{
	perror(string_error);//¿Cambiar por ft_printf para evitar el errno en el output?
	exit(1);
}

char	*read_file(int map_fd)
{
	char	*map;
	char	*aux;
	char	*map_line;

	map = NULL;
	map_line = get_next_line(map_fd);
	while (map_line)
	{
		aux = map;
		map = ft_strjoin(map, map_line);
		if (aux)
			free(aux);
		free(map_line);
		map_line = get_next_line(map_fd);
	}
	return (map);
}

t_player	*init_player(t_mlx_player *mlx_player)
{
	mlx_player->player = malloc(sizeof(t_player));
	mlx_player->player->x = 0;
	mlx_player->player->y = 0;
	mlx_player->player->texture = mlx_load_png("tuxy_resized.png");
	mlx_player->player->image_tuxy = mlx_texture_to_image(mlx_player->mlx, mlx_player->player->texture);
	return (mlx_player->player);
}

t_map	*init_map(t_mlx_player *mlx_player, int map_fd)
{
	mlx_player->map = malloc(1 * sizeof(t_map));
	/*mlx_player->map->x = 0;
	mlx_player->map->y = 0;*/
	/*mlx_player->map->map = malloc((lines + 1) * sizeof(char *));
	mlx_player->map->map[lines] = NULL;*/
	mlx_player->map->map = ft_split(read_file(map_fd), '\n');
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

void	calc_map_rows_columns(t_mlx_player *mlx_player)
{
	int	i;
	int	j;
	
	i = 0;
	while (mlx_player->map->map[0][i])
		i++;
	j = 0;
	while (mlx_player->map->map[j])
		j++;
	mlx_player->map->colums = i;
	mlx_player->map->rows = j;
}

void	malloc_map(int length, int rows, t_mlx_player *mlx_player)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < length)
		{
			mlx_player->map->map[i] = malloc(((length + 1) * sizeof(char)));
			j++;
		}
		i++;
	}
}

void	check_map_has_minimum_size(t_mlx_player *mlx_player)
{
	if ((mlx_player->map->rows >= 3 && mlx_player->map->colums >= 5)
		|| (mlx_player->map->rows >= 5 && mlx_player->map->colums >= 3))
		return ;
	else
		throw_error(STR_INVALID_MAP_SIZE);
}

int	check_map_rows_length_is_rectangular(t_mlx_player *mlx_player)
{
	int i;
	int	length;

	length = ft_strlen(*(mlx_player->map->map));
	i = 0;
	while (mlx_player->map->map[i])
	{
		if (!(length == ft_strlen(mlx_player->map->map[i])))
			throw_error("The map has different length in its rows");
		i++;
	}
	return (length);
}

void	check_map_horizontal_walls(t_mlx_player *mlx_player)
{
	int	i;
	int	j;

	i = 0;
	while (mlx_player->map->map[i])
	{	
		j = 0;
		if (mlx_player->map->map[i][0] != '1')
			throw_error(STR_INVALID_HORIZONTAL_FIRST_CELL);
		while (mlx_player->map->map[i][j])
			j++;
		if (mlx_player->map->map[i][j - 1] != '1')
			throw_error(STR_INVALID_HORIZONTAL_LAST_CELL);
		i++;
	}
}

void	check_map_surrounded_walls(t_mlx_player *mlx_player)
{
	int	i;

	i = 0;
	while (mlx_player->map->map[0][i] == '1')
		i++;
	//printf("The cell value is: %i %s %i\n", mlx_player->map->map[0][i], __FILE__, __LINE__);
	if (mlx_player->map->map[0][i] != 0)
		throw_error("All the cells of the first row of the map aren't walls");
	i = 0;
	while (mlx_player->map->map[mlx_player->map->rows - 1][i] == '1')
		i++;
	if (mlx_player->map->map[mlx_player->map->rows - 1][i] != 0)
		throw_error("All the cells of the last row of the map aren't walls");
	check_map_horizontal_walls(mlx_player);
		//printf("The first row of the map is all wall %s %i\n", __FILE__, __LINE__);
}

void	check_map_game_elements(t_mlx_player *mlx_player)
{
	int	i;
	int	j;
	int32_t	player_number;
	int32_t	exit_number;
	int32_t	collectable_number;

	player_number = 0;
	exit_number = 0;
	collectable_number = 0;
	i = 0;
	while (mlx_player->map->map[i])
	{
		j = 0;
		while (mlx_player->map->map[i][j])
		{
			//printf("Map cell value is: %c %s %i\n", mlx_player->map->map[i][j], __FILE__, __LINE__);
			if (mlx_player->map->map[i][j] == 'P')
				player_number += 1;
			else if (mlx_player->map->map[i][j] == 'E')
				exit_number += 1;
			else if (mlx_player->map->map[i][j] == 'C')
				collectable_number += 1;
			else if (mlx_player->map->map[i][j] != '0'
				&& mlx_player->map->map[i][j] != '1'
				&& mlx_player->map->map[i][j] != '\n')
				throw_error("The map has something that doesn't belong there");
			j++;
		}
		i++;
	}
	if (player_number != 1 || exit_number != 1 || collectable_number < 1)
		throw_error("The map isn't correct in terms of map elements");
}

void	check_map_wrong(t_mlx_player *mlx_player)
{
	calc_map_rows_columns(mlx_player);
	check_map_has_minimum_size(mlx_player);
	check_map_rows_length_is_rectangular(mlx_player);
	check_map_surrounded_walls(mlx_player);
	check_map_game_elements(mlx_player);
}

void	check_valid_map(t_mlx_player *mlx_player)
{

}

void	check_map(t_mlx_player *mlx_player)
{
	check_map_wrong(mlx_player);
	check_valid_map(mlx_player);
}

int	read_map(t_mlx_player *mlx_player)
{
	int		rows;
	int		map_fd;
	char	*line;
	int		char_nu;
	int		length;
	
	map_fd = open(MAP_FILE, O_RDONLY);
	if (map_fd == -1)
		return (1);
	printf("Map fd is: %i %s %i\n", map_fd, __FILE__, __LINE__);
	line = get_next_line(map_fd);
	//length = ft_strlen(*(mlx_player->map->map));
	length = ft_strlen(line);
	malloc_map(length, 42, mlx_player);// Replace the function call
	while (line)
	{
		line = get_next_line(map_fd);
		free(line);
		rows++;
	}
	close(map_fd);
	map_fd = open(MAP_FILE, O_RDONLY);
	if (map_fd == -1)
		return (1);
	printf("Map fd is: %i %s %i\n", map_fd, __FILE__, __LINE__);
	line = get_next_line(map_fd);
	char_nu = 0;
	while (line)
	{
		mlx_player->map->map[rows] = get_next_line(map_fd);
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
	//mlx_player->map->map[0] = NULL;
	return (rows);
}

void	print_map(t_mlx_player *mlx_player)
{
	int i;
	int	j;

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
}

void	paint_map(t_mlx_player *mlx_player)
{
	//Rewrite the function to be variable given the map file
	int	row;
	int	col;
	/*int	index;
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
	}*/
	row = 0;
	while (row < mlx_player->map->rows)
	{
		//printf("Testing the paint loop %s %i\n", __FILE__, __LINE__);
		col = 0;
		while (col < mlx_player->map->colums)
		{
			//printf("Testing the paint loop in loop %s %i\n", __FILE__, __LINE__);
			//printf("Printing map cell value: %c %s %i\n", mlx_player->map->map[row][col], __FILE__, __LINE__);
			if((mlx_player->map->map[row][col]) == '0')
			{
				mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, /*mlx_player->map->x*/ /* + ( */col * TILE_WIDTH/* ) */, /* mlx_player->map->y */ /* + ( */row * TILE_HEIGHT)/* ) */;
				printf("Printing the floor times: %i %s %i\n", (int)col, __FILE__, __LINE__);
			}
			else if ((mlx_player->map->map[row][col]) == '1')
			{
				mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_wall, /*mlx_player->map->x*/ /* + ( */col * TILE_WIDTH/* ) */, /*mlx_player->map->y*/ /* + ( */row * TILE_HEIGHT)/* ) */;
				//printf("Testing the paint loop in wall %s %i\n", __FILE__, __LINE__);
			}
			else if ((mlx_player->map->map[row][col] == 'P'))
				mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
			printf("Printing the colum value: %i %s %i\n", (int)col, __FILE__, __LINE__);
			col++;
			printf("Printing the row value: %i %s %i\n", (int)row, __FILE__, __LINE__);
		}
		row++;
	}
}

void	swap_layers(t_mlx_player *mlx_player)
{
	mlx_set_instance_depth(mlx_player->player->image_tuxy->instances, 17);
}

void	move_player_right(t_mlx_player *mlx_player)
{
	printf("Testing the right movement %s %i\n", __FILE__, __LINE__);
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
		printf("Testing width %i %s %i\n", mlx_player->mlx->width, __FILE__, __LINE__);
		printf("Testing the D key pressed %s %i\n", __FILE__, __LINE__);
		if ((mlx_player->player->x + mlx_player->player->image_tuxy->width) > mlx_player->mlx->width)
		{
			printf("Testing the D keypress %s %i\n", __FILE__, __LINE__);
			return ;
		}
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
	t_mlx_player	*mlx_player; // It 
	//int		map[] = {1, 0, 1, 1, 0, 1, 0, 1};
	int		map_fd;
	
	map_fd = open(MAP_FILE, O_RDONLY);
	if (map_fd == -1)
		return (1);

//	int length = 8;
	mlx_player = malloc(sizeof(t_mlx_player));
	//ft_atoi(NULL);
	mlx_player->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", false);
	mlx_player->player = init_player(mlx_player);
	mlx_player->map = init_map(mlx_player, map_fd);
	check_map(mlx_player);

	//mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x, mlx_player->map->y);
//	mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_floor, mlx_player->map->x+FLOOR_WIDTH, mlx_player->map->y);
//	open_map(map_fd);
	//map_fd = open(MAP_FILE, O_RDONLY);
	//read_map(mlx_player);
	if (mlx_player->map->map == NULL)
		return (printf("Could not read map\n"));
	print_map(mlx_player);
	paint_map(mlx_player);
	//mlx_image_to_window(mlx_player->mlx, mlx_player->player->image_tuxy, mlx_player->player->x, mlx_player->player->y);

	mlx_key_hook(mlx_player->mlx, &my_keyhook, mlx_player);
	//swap_layers(mlx_player);

	mlx_loop(mlx_player->mlx);
	destroy_player(mlx_player);
	free(mlx_player->player);
	mlx_terminate(mlx_player->mlx);
	close(map_fd);

	return(0);
}
