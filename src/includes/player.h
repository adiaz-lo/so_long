#ifndef PLAYER_H
# define PLAYER_H

# include "common.h"

typedef struct s_map
{
	char			**map;
	uint32_t		rows;
	uint32_t		columns;
}   t_map;

typedef struct  s_textures
{
    uint32_t         x;
	uint32_t         y;
    uint32_t		cell_nu;
	mlx_texture_t   *floor_tex;
	mlx_image_t     *floor_img;
	mlx_texture_t   *wall_tex;
	mlx_image_t     *wall_img;
	mlx_texture_t   *collec_tex;
	mlx_image_t     *collec_img;
	mlx_texture_t   *exit_tex;
	mlx_image_t     *exit_img;
}   t_textures;

typedef struct s_player
{
	uint32_t         x;
	uint32_t         y;
	uint32_t         speed;
	mlx_texture_t   *player_tex;
	mlx_image_t     *player_img;
}   t_player;

typedef struct s_game
{
	t_player	*player;
	t_map		*map;
	mlx_t		*mlx;
}	t_game;

#endif
