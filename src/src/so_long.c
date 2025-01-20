#include "so_long.h"

// void destroy_player(t_mlx_player *mlx_player) {
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   mlx_delete_image(mlx_player->mlx, mlx_player->player->image_tuxy);
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   printf("%s:%i\n", __FILE__, __LINE__);
//   printf("%s:%i\n", __FILE__, __LINE__);
// }

// void calc_map_rows_columns(t_mlx_player *mlx_player) {
//   int i;
//   int j;

//   i = 0;
//   while (mlx_player->map->map[0][i])
//     i++;
//   j = 0;
//   while (mlx_player->map->map[j])
//     j++;
//   mlx_player->map->columns = i;
//   mlx_player->map->rows = j;
// }

// void malloc_map(int length, int rows, t_mlx_player *mlx_player) {
//   int i;
//   int j;

//   i = 0;
//   while (i < rows) {
//     j = 0;
//     while (j < length) {
//       mlx_player->map->map[i] = malloc(((length + 1) * sizeof(char)));
//       if (!mlx_player->map->map[i])
//         throw_error("The memory allocation of the cell has failed");
//       j++;
//     }
//     i++;
//   }
// }

// void check_map_has_minimum_size(t_mlx_player *mlx_player) {
//   if ((mlx_player->map->rows >= 3 && mlx_player->map->columns >= 5) ||
//       (mlx_player->map->rows >= 5 && mlx_player->map->columns >= 3))
//     return;
//   else
//     throw_error(STR_INVALID_MAP_SIZE);
// }

// int check_map_rows_length_is_rectangular(t_mlx_player *mlx_player) {
//   int           i;
//   unsigned int  length;

//   length = ft_strlen(*(mlx_player->map->map));
//   i = 0;
//   while (mlx_player->map->map[i]) {
//     if (!(length == ft_strlen(mlx_player->map->map[i])))
//       throw_error("The map has different length in its rows");
//     i++;
//   }
//   return (length);
// }

// void check_map_horizontal_walls(t_mlx_player *mlx_player) {
//   int i;
//   int j;

//   i = 0;
//   while (mlx_player->map->map[i]) {
//     j = 0;
//     if (mlx_player->map->map[i][0] != '1')
//       throw_error(STR_INVALID_HORIZONTAL_FIRST_CELL);
//     while (mlx_player->map->map[i][j])
//       j++;
//     if (mlx_player->map->map[i][j - 1] != '1')
//       throw_error(STR_INVALID_HORIZONTAL_LAST_CELL);
//     i++;
//   }
// }

// void check_map_surrounded_walls(t_mlx_player *mlx_player) {
//   int i;

//   i = 0;
//   while (mlx_player->map->map[0][i] == '1')
//     i++;
//   if (mlx_player->map->map[0][i] != 0)
//     throw_error("All the cells of the first row of the map aren't walls");
//   i = 0;
//   while (mlx_player->map->map[mlx_player->map->rows - 1][i] == '1')
//     i++;
//   if (mlx_player->map->map[mlx_player->map->rows - 1][i] != 0)
//     throw_error("All the cells of the last row of the map aren't walls");
//   check_map_horizontal_walls(mlx_player);
// }

// void check_map_game_elements(t_mlx_player *mlx_player) {
//   int i;
//   int j;
//   int32_t player_number;
//   int32_t exit_number;
//   int32_t collectable_number;

//   player_number = 0;
//   exit_number = 0;
//   collectable_number = 0;
//   i = 0;
//   while (mlx_player->map->map[i]) {
//     j = 0;
//     while (mlx_player->map->map[i][j]) {
//       if (mlx_player->map->map[i][j] == 'P')
//         player_number += 1;
//       else if (mlx_player->map->map[i][j] == 'E')
//         exit_number += 1;
//       else if (mlx_player->map->map[i][j] == 'C')
//         collectable_number += 1;
//       else if (mlx_player->map->map[i][j] != '0' &&
//                mlx_player->map->map[i][j] != '1' &&
//                mlx_player->map->map[i][j] != '\n')
//         throw_error("The map has something that doesn't belong there");
//       j++;
//     }
//     i++;
//   }
//   if (player_number != 1 || exit_number != 1 || collectable_number < 1)
//     throw_error("The map isn't correct in terms of map elements");
// }

// void check_map_wrong(t_mlx_player *mlx_player) {
//   calc_map_rows_columns(mlx_player);
//   check_map_has_minimum_size(mlx_player);
//   check_map_rows_length_is_rectangular(mlx_player);
//   check_map_surrounded_walls(mlx_player);
//   check_map_game_elements(mlx_player);
// }

// /*void check_valid_map(t_mlx_player *mlx_player) {}
// */

// void check_map(t_mlx_player *mlx_player) {
//   check_map_wrong(mlx_player);
// //  check_valid_map(mlx_player);
// }

// //Check empty file, file exists, errors returns fd of map
// int read_map(t_mlx_player *mlx_player, char *map) {
//   int rows;
//   int map_fd;
//   char *line;
//   int length;
//   int i;

//   map_fd = open(map, O_RDONLY);
//   if (map_fd == -1)
//     return (1);
//   line = get_next_line(map_fd);
//   length = ft_strlen(line);
//   rows = 0;
//   while (line) {
//     free(line);
//     rows++;
//     line = get_next_line(map_fd);
//   }
//   printf("Rows' value is: %i %s %i\n", rows, __FILE__, __LINE__);
//   malloc_map(length, rows, mlx_player);
//   close(map_fd);
//   map_fd = open(map, O_RDONLY);
//   if (map_fd == -1)
//     return (1);
//   line = get_next_line(map_fd);
//   printf("Debug number 42: %s %i\n", __FILE__, __LINE__);
// //  mlx_player->map->cell_nu = (rows * (ft_strlen(line) - 1)) + 1;
//   i = rows - 2;
//   mlx_player->map->map[i] = line;
//   while (i >= 0) {
//     line = get_next_line(map_fd);
//     mlx_player->map->map[i] = line;
//     printf("Debugging Map Reading %i ---------- %s\n", i,
//     mlx_player->map->map[i]); i--;
//   }

//   mlx_player->map->map[rows] = NULL;
//   printf("Debugging Map Reading ---------- %s\n", mlx_player->map->map[0]);
//   close(map_fd);
//   mlx_player->map->rows = rows;
//   mlx_player->map->columns =
//       ft_strlen(mlx_player->map->map[0]) - 1; // Resta 1 para no contar el
//       '\n'
//  // mlx_player->map->cell_nu = rows * mlx_player->map->columns;
//   return (rows);
// }

// void print_map(t_mlx_player *mlx_player) {
//   int i;
//   int j;

//   i = 0;
//   while (mlx_player->map->map[i]) {
//     j = 0;
//     while (mlx_player->map->map[i][j]) {
//       printf("%c", mlx_player->map->map[i][j]);
//       j++;
//     }
//     printf("\n");
//     i++;
//   }
// }

// void paint_map(t_mlx_player *mlx_player) {
//   uint32_t y;
//   uint32_t x;
//   y = 0;
//   while (y < mlx_player->map->rows) {
//     x = 0;
//     while (x < mlx_player->map->columns) {
//       if ((mlx_player->map->map[y][x]) == '0') {
//   //      mlx_image_to_window(mlx_player->mlx, mlx_player->map->floor_img,
//     //        y * TILE_SIZE, x * TILE_SIZE);
//         printf("Printing the floor times: %i %s %i\n", (int)x,
//         __FILE__,__LINE__);
//       } else if ((mlx_player->map->map[y][x]) == '1') {
//      //   mlx_image_to_window(mlx_player->mlx, mlx_player->map->wall_img,
//      //       y * TILE_SIZE, x * TILE_SIZE);
//       } else if ((mlx_player->map->map[y][x]) == 'P') {
//         mlx_player->player->x = x;
//         mlx_player->player->y = y;
//         printf("Printing x: %i | y: %i | %s %i\n", x, y, __FILE__, __LINE__);
//         // mlx_image_to_window(mlx_player->mlx, mlx_player->map->floor_img,
//                             // y * TILE_SIZE, x * TILE_SIZE);
//         // mlx_image_to_window(mlx_player->mlx,
//         mlx_player->player->image_tuxy,
//                             // y * TILE_SIZE, x * TILE_SIZE);
//       } else if ((mlx_player->map->map[y][x]) == 'C') {
//         // mlx_image_to_window(mlx_player->mlx, mlx_player->map->floor_img,
//                             // y * TILE_SIZE, x * TILE_SIZE);
//         // mlx_image_to_window(mlx_player->mlx, mlx_player->map->collec_img,
//                             // y * TILE_SIZE, x * TILE_SIZE);
//       } else if ((mlx_player->map->map[y][x]) == 'E') {
//         // mlx_image_to_window(mlx_player->mlx, mlx_player->map->floor_img,
//                             // y * TILE_SIZE, x * TILE_SIZE);
//         // mlx_image_to_window(mlx_player->mlx, mlx_player->map->image_exit,
//         //                     y * TILE_SIZE, x * TILE_SIZE);
//       }
//       printf("Printing the colum value: %i %s %i\n", (int)x, __FILE__,
//       __LINE__); x++;
//     }
//     printf("Printing the row value: %i %s %i\n", (int)y, __FILE__, __LINE__);
//     y++;
//   }
// }

// /*void swap_layers(t_mlx_player *mlx_player) {
//   mlx_set_instance_depth(mlx_player->player->image_tuxy->instances,
//                          mlx_player->map->cell_nu);
//   printf("The cell numbers value is: %i %s %i\n", mlx_player->map->cell_nu,
//   __FILE__, __LINE__);
//   }*/

// void move_player_right(t_mlx_player *mlx_player) {
//   printf("Testing the right movement %s %i\n", __FILE__, __LINE__);
//   mlx_player->player->x += TILE_SIZE;
//   mlx_player->player->image_tuxy->instances->x += TILE_SIZE;
// }

// void move_player_left(t_mlx_player *mlx_player) {
//   mlx_player->player->x -= TILE_SIZE;
//   mlx_player->player->image_tuxy->instances->x -= TILE_SIZE;
// }

// void move_player_down(t_mlx_player *mlx_player) {
//   mlx_player->player->y += TILE_SIZE;
//   mlx_player->player->image_tuxy->instances->y += TILE_SIZE;
// }

// void move_player_up(t_mlx_player *mlx_player) {
//   mlx_player->player->y -= TILE_SIZE;
//   mlx_player->player->image_tuxy->instances->y -= TILE_SIZE;
// }

// void my_keyhook(mlx_key_data_t keydata, void *param) {
//   t_mlx_player *mlx_player = (t_mlx_player *)param;
//   if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//     mlx_close_window(mlx_player->mlx);
//   if (keydata.key == MLX_KEY_D &&
//       (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
//     printf("Testing width %i %s %i\n", mlx_player->mlx->width, __FILE__,
//            __LINE__);
//     printf("Testing the D key pressed %s %i\n", __FILE__, __LINE__);
//     if ((mlx_player->player->x + mlx_player->player->image_tuxy->width)
//         > (uint32_t)mlx_player->mlx->width)
//     {
//       printf("Testing the D keypress %s %i\n", __FILE__, __LINE__);
//       return;
//     }
//     move_player_right(mlx_player);
//     printf("x coordinate value: %d\n", mlx_player->player->x);
//     printf("Canvas Width: %d\n", mlx_player->player->x);
//     printf("Image Width: %d\n", mlx_player->player->x);
//   }
//   if (keydata.key == MLX_KEY_S &&
//       (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
//     printf("Testing the limits\n");
//     if ((mlx_player->player->y + mlx_player->player->image_tuxy->height)
//         > (uint32_t)mlx_player->mlx->height)
//       return;
//     printf("Testing the limits\n");
//     move_player_down(mlx_player);
//     printf("%d\n", mlx_player->player->y);
//   }
//   if (keydata.key == MLX_KEY_A &&
//       (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
//     if ((mlx_player->player->x - mlx_player->player->image_tuxy->width)
//         <= (uint32_t)mlx_player->mlx->width)
//       return;
//     move_player_left(mlx_player);
//   }
//   if (keydata.key == MLX_KEY_W &&
//       (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
//     if ((mlx_player->player->y - mlx_player->player->image_tuxy->height)
//         <= (uint32_t)mlx_player->mlx->height)
//       return;
//     move_player_up(mlx_player);
//   }
// }

int validate_map_name(char *map_name) {
  char *map_extension;
  int result;
  int size;

  size = ft_strlen(MAP_EXTENSION);
  // Check
  map_extension = ft_substr(map_name, ft_strlen(map_name) - size, size);
  result = ft_strncmp(".ber", map_extension, size);
  if (result == 0)
    return (1);
  return (0);
}

int32_t main(int argc, char **argv) {
  // t_mlx_player *mlx_player; // It
  int map_fd;
  t_map map;

  if (argc != 2)
    throw_error("The number of arguments you've inputed is different than 2, "
                "you must have 2 arguments");
  if (!validate_map_name(argv[1]))
    throw_error("The map file you've tried isn't a *.ber file");
  // map->map = malloc(size_t size);
  map_fd = open_file(argv[1]);
  map.map = read_file(map_fd);
  // map = init_map(map_fd);

  // mlx_player = malloc(sizeof(t_mlx_player));
  // mlx_player->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", false);
  // mlx_player->player = init_player(mlx_player);
  // // mlx_player->map = init_map(mlx_player, map_fd);
  // check_map(mlx_player);

  // read_map(mlx_player, argv[1]);
  // if (mlx_player->map->map == NULL)
  //   return (printf("Could not read map\n"));
  // print_map(mlx_player);
  // paint_map(mlx_player);

  // mlx_key_hook(mlx_player->mlx, &my_keyhook, mlx_player);
  // swap_layers(mlx_player);

  // mlx_loop(mlx_player->mlx);
  // destroy_player(mlx_player);
  // free(mlx_player->player);
  // mlx_terminate(mlx_player->mlx);
  // close(map_fd);
  clean(map.map, map_fd);

  return (0);
}
