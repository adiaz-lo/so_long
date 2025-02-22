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
  player->player_tex = mlx_load_png("./sprites/tuxy_resized.png");
  player->player_img = NULL;
      // mlx_texture_to_image(mlx, player->texture);
}

//*init_textures(t)
/*{
mlx_player->map->floor_tex = mlx_load_png("./sprites/floor.png");
 mlx_player->map->floor_img =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->floor_tex);
 mlx_player->map->wall_tex = mlx_load_png("./sprites/wall_final.png");
 mlx_player->map->wall_img =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->wall_tex);
 mlx_player->map->collec_tex = mlx_load_png("./sprites/win.png");
 mlx_player->map->collec_img = mlx_texture_to_image(
     mlx_player->mlx, mlx_player->map->collec_tex);
 mlx_player->map->texture_exit =
mlx_load_png("./sprites/arch_transparent_borders.png");
 mlx_player->map->image_exit =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->texture_exit);
     }*/

// void init_map(char *mapfile, t_map *map) {
  // mlx_player->map = malloc(1 * sizeof(t_map));
  // mlx_player->map->cell_nu = 0;
  // mlx_player->map->map = ft_split(read_file(map_fd), '\n');
    // map.map = read_file(mapfile, &map);
  // Abre el mapa, lee el mapa, cierra el mapa y retorna el mapa
  // return (mlx_player->map);
// }
