#ifndef PLAYER_H
#define PLAYER_H

typedef struct s_map
{
	uint32_t         x;
	uint32_t         y;
	char			**map;
	mlx_texture_t   *texture_floor;
	mlx_image_t     *image_floor;
	mlx_texture_t   *texture_wall;
	mlx_image_t     *image_wall;
}   t_map;

typedef struct s_player
{
	uint32_t         x;
	uint32_t         y;
	uint32_t         speed;
	mlx_texture_t   *texture;
	mlx_image_t     *image_tuxy;
}       t_player;

typedef struct mlx_player
{
	t_player	*player;
	t_map		*map;
	mlx_t		*mlx;
}	t_mlx_player;

#endif
