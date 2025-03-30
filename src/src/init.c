#include "so_long.h"

// t_player *init_player(t_player player) {
//   player = malloc(sizeof(t_player));
//   player.x = 0;
//   player.y = 0;
//   player->player_tex = mlx_load_png("./sprites/tuxy_resized.png");
//   player->player_img = NULL;
//       // mlx_texture_to_image(mlx, player->texture);
//   return (player);
// }

void init_player(t_player *player) {
  // player = malloc(sizeof(t_player));
  player->x = 0;
  player->y = 0;
  player->speed = 1;
  // player->player_img = NULL;
  // mlx_texture_to_image(mlx, player->texture);
}

void init_textures(t_textures *textures) {
  textures->player.path = mlx_load_png("./sprites/tuxy_resized.png");
  textures->floor.path = mlx_load_png("./sprites/floor.png");
  textures->wall.path = mlx_load_png("./sprites/wall_final.png");
  textures->collectable.path = mlx_load_png("./sprites/win.png");
  textures->exit.path = mlx_load_png("./sprites/arch_transparent_borders.png");
}

// void init_map(char *mapfile, t_map *map) {
// mlx_player->map = malloc(1 * sizeof(t_map));
// mlx_player->map->cell_nu = 0;
// mlx_player->map->map = ft_split(read_file(map_fd), '\n');
// map.map = read_file(mapfile, &map);
// Abre el mapa, lee el mapa, cierra el mapa y retorna el mapa
// return (mlx_player->map);
// }

void init_game(t_game *game, t_map *map, t_player *player, t_textures *tex) {
  game->map = *map;
  game->player = *player;
  game->textures = *tex;
  init_player(&game->player);
  init_textures(&game->textures);
}
