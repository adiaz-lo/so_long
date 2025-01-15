#include "so_long.h"

t_player *init_player(t_mlx_player *mlx_player) {
  mlx_player->player = malloc(sizeof(t_player));
  mlx_player->player->x = 0;
  mlx_player->player->y = 0;
  mlx_player->player->texture = mlx_load_png("./sprites/tuxy_resized.png");
  mlx_player->player->image_tuxy =
      mlx_texture_to_image(mlx_player->mlx, mlx_player->player->texture);
  return (mlx_player->player);
}
//*init_textures(t)
{
mlx_player->map->floor_tex = mlx_load_png("./sprites/floor.png");
 mlx_player->map->floor_img =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->floor_tex);
 mlx_player->map->wall_tex = mlx_load_png("./sprites/wall_final.png");
 mlx_player->map->wall_img =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->wall_tex);
 mlx_player->map->collec_tex = mlx_load_png("./sprites/win.png");
 mlx_player->map->collec_img = mlx_texture_to_image(
     mlx_player->mlx, mlx_player->map->collec_tex);
 mlx_player->map->texture_exit = mlx_load_png("./sprites/arch_transparent_borders.png");
 mlx_player->map->image_exit =
     mlx_texture_to_image(mlx_player->mlx, mlx_player->map->texture_exit);


t_map *init_map(t_mlx_player *mlx_player, int map_fd) {
  mlx_player->map = malloc(1 * sizeof(t_map));
  mlx_player->map->cell_nu = 0;
  mlx_player->map->map = ft_split(read_file(map_fd), '\n');

  return (mlx_player->map);
}
