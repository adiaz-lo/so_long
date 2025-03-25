#include "so_long.h"

// void destroy_player(t_game *game) {
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   mlx_delete_image(game->mlx, game->player->player_img);
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   printf("Testing the limits %s %i\n", __FILE__, __LINE__);
//   printf("%s:%i\n", __FILE__, __LINE__);
//   printf("%s:%i\n", __FILE__, __LINE__);
// }

void check_map(t_map map, t_player *player) {
  check_map_wrong(&map);
  check_map_valid(&map, player);
}

// //Check empty file, file exists, errors returns fd of map
// int read_map(t_game *game, char *map) {
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
//   malloc_map(length, rows, game);
//   close(map_fd);
//   map_fd = open(map, O_RDONLY);
//   if (map_fd == -1)
//     return (1);
//   line = get_next_line(map_fd);
//   printf("Debug number 42: %s %i\n", __FILE__, __LINE__);
// //  game->map->cell_nu = (rows * (ft_strlen(line) - 1)) + 1;
//   i = rows - 2;
//   game->map->map[i] = line;
//   while (i >= 0) {
//     line = get_next_line(map_fd);
//     game->map->map[i] = line;
//     printf("Debugging Map Reading %i ---------- %s\n", i,
//     game->map->map[i]); i--;
//   }

//   game->map->map[rows] = NULL;
//   printf("Debugging Map Reading ---------- %s\n", game->map->map[0]);
//   close(map_fd);
//   game->map->rows = rows;
//   game->map->columns =
//       ft_strlen(game->map->map[0]) - 1; // Resta 1 para no contar el
//       '\n'
//  // game->map->cell_nu = rows * game->map->columns;
//   return (rows);
// }

void paint_map(t_game *game) {
  int32_t y;
  int32_t x;
  y = 0;

  while (y < game->map.y) {
    x = 0;
    while (x < game->map.x) {
      if ((game->map.map[y][x]) == '0') {
        mlx_image_to_window(game->mlx, game->textures.floor.img, y * TILE_SIZE,
                            x * TILE_SIZE);
        printf("Printing the floor times: %i %s %i\n", (int)x, __FILE__,
               __LINE__);
      } else if ((game->map.map[y][x]) == '1') {
        mlx_image_to_window(game->mlx, game->textures.wall.img, y * TILE_SIZE,
                            x * TILE_SIZE);
      } else if ((game->map.map[y][x]) == 'P') {
        game->player.x = x;
        game->player.y = y;
        printf("Printing x: %i | y: %i | %s %i\n", x, y, __FILE__, __LINE__);
        mlx_image_to_window(game->mlx, game->textures.floor.img, y * TILE_SIZE,
                            x * TILE_SIZE);
        mlx_image_to_window(game->mlx, game->textures.player.img, y * TILE_SIZE,
                            x * TILE_SIZE);
      } else if ((game->map.map[y][x]) == 'C') {
        mlx_image_to_window(game->mlx, game->textures.floor.img, y * TILE_SIZE,
                            x * TILE_SIZE);
        mlx_image_to_window(game->mlx, game->textures.collectable.img,
                            y * TILE_SIZE, x * TILE_SIZE);
      } else if ((game->map.map[y][x]) == 'E') {
        mlx_image_to_window(game->mlx, game->textures.floor.img, y * TILE_SIZE,
                            x * TILE_SIZE);
        mlx_image_to_window(game->mlx, game->textures.exit.img, y * TILE_SIZE,
                            x * TILE_SIZE);
      }
      printf("Printing the colum value: %i %s %i\n", (int)x, __FILE__,
             __LINE__);
      x++;
    }
    printf("Printing the row value: %i %s %i\n", (int)y, __FILE__, __LINE__);
    y++;
  }
}

// /*void swap_layers(t_game *game) {
//   mlx_set_instance_depth(game->player->player_img->instances,
//                          game->map->cell_nu);
//   printf("The cell numbers value is: %i %s %i\n", game->map->cell_nu,
//   __FILE__, __LINE__);
//   }*/

void move_player_right(t_game *game) {
  printf("Testing the right movement %s %i\n", __FILE__, __LINE__);
  game->player.x += TILE_SIZE;
  game->textures.player.img->instances->x += TILE_SIZE;
}

void move_player_left(t_game *game) {
  game->player.x -= TILE_SIZE;
  game->textures.player.img->instances->x -= TILE_SIZE;
}

void move_player_down(t_game *game) {
  game->player.y += TILE_SIZE;
  game->textures.player.img->instances->y += TILE_SIZE;
}

void move_player_up(t_game *game) {
  game->player.y -= TILE_SIZE;
  game->textures.player.img->instances->y -= TILE_SIZE;
}

void my_keyhook(mlx_key_data_t keydata, void *param) {
  t_game *game = (t_game *)param;
  if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    mlx_close_window(game->mlx);
  if (keydata.key == MLX_KEY_D &&
      (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
    printf("Testing width %i %s %i\n", game->mlx->width, __FILE__, __LINE__);
    printf("Testing the D key pressed %s %i\n", __FILE__, __LINE__);
    if ((game->player.x + game->textures.player.img->width) >
        (uint32_t)game->mlx->width) {
      printf("Testing the D keypress %s %i\n", __FILE__, __LINE__);
      return;
    }
    move_player_right(game);
    printf("x coordinate value: %d\n", game->player.x);
    printf("Canvas Width: %d\n", game->player.x);
    printf("Image Width: %d\n", game->player.x);
  }
  if (keydata.key == MLX_KEY_S &&
      (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
    printf("Testing the limits\n");
    if ((game->player.y + game->textures.player.img->height) >
        (uint32_t)game->mlx->height)
      return;
    printf("Testing the limits\n");
    move_player_down(game);
    printf("%d\n", game->player.y);
  }
  if (keydata.key == MLX_KEY_A &&
      (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
    if ((game->player.x - game->textures.player.img->width) <=
        (uint32_t)game->mlx->width)
      return;
    move_player_left(game);
  }
  if (keydata.key == MLX_KEY_W &&
      (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) {
    if ((game->player.y - game->textures.player.img->height) <=
        (uint32_t)game->mlx->height)
      return;
    move_player_up(game);
  }
}

int validate_map_name(char *map_name) {
  char *map_extension;
  int result;
  int size;

  size = ft_strlen(MAP_EXTENSION);
  // Check
  map_extension = ft_substr(map_name, ft_strlen(map_name) - size, size);
  result = ft_strncmp(".ber", map_extension, size);
  free(map_extension);
  if (result == 0)
    return (1);
  return (0);
}

int32_t main(int argc, char **argv) {
  // t_game *game; // It
  // int map_fd;
  t_game game;
  t_map map;
  t_player player;
  t_textures textures;

  if (argc != 2)
    throw_error("The number of arguments you've inputed is different than 2, "
                "you must have 2 arguments");
  if (!validate_map_name(argv[1]))
    throw_error("The map file you've tried isn't a *.ber file");
  // map->map = malloc(size_t size);
  // map_fd = open_file(argv[1]);
  init_game(&game, &map, &player, &textures);
  read_file(argv[1], &map);
  // map = init_map(map_fd);
  check_map(map, &player);
  init_textures(&textures);
  game.mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", false);
  mlx_key_hook(game.mlx, &my_keyhook, &game);

  // game = malloc(sizeof(t_game));
  // game->mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", false);
  // game->player = init_player(game);
  // // game->map = init_map(game, map_fd);
  // check_map(game);

  // read_map(game, argv[1]);
  // if (game->map->map == NULL)
  //   return (printf("Could not read map\n"));
  // print_map(game);
  paint_map(&game);

  // mlx_key_hook(game->mlx, &my_keyhook, game);
  // swap_layers(game);

  mlx_loop(game.mlx);
  // destroy_player(game);
  // free(game->player);
  // mlx_terminate(game->mlx);
  // close(map_fd);
  // clean(map.map, map_fd);
  // clean(map.map);

  return (0);
}
