#ifndef PLAYER_H
#define PLAYER_H

typedef struct s_player
{
    int32_t         x;
    int32_t         y;
    int32_t         speed;
    mlx_texture_t   *texture;
    mlx_image_t     *image_tuxy;
}       t_player;

typedef struct mlx_player
{
    t_player    *player;
    mlx_t       *mlx;
}   t_mlx_player;

#endif