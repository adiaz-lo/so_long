#ifndef PLAYER_H
# define PLAYER_H

# include "common.h"

/*
    Texture struct
    int32_t         width;  -> Texture width
    int32_t         height; -> Texture height
    mlx_texture_t   *path;  -> Texture file path
    mlx_image_t     *img;   -> MLX Image pointer
*/
typedef struct  s_texture
{
    int32_t         width;
    int32_t         height;
    mlx_texture_t   *path;
    mlx_image_t     *img;
}   t_texture;

/*
    Textures struct
    t_texture   player;         -> Player texture
    t_texture   wall;           -> Wall texture
    t_texture   collectible;    -> Collectible item texture
    t_texture   exit;           -> Exit texture
    t_texture   floor;          -> Floor/empty space texture

    // Optional: Additional textures for visual enhancement
    t_texture   exit_open;      -> Exit when all collectibles are gathered
*/
typedef struct  s_textures
{
 //    uint32_t         x;
	// uint32_t         y;
    // uint32_t		cell_nu;
    t_texture   player;
    t_texture   wall;
    t_texture   collectable;
    t_texture   exit;
    t_texture   floor;
    t_texture   exit_open;
}   t_textures;

typedef struct s_map
{
	char       **map;
	int32_t    y;
	int32_t    x;
}   t_map;

typedef struct s_player
{
	uint32_t         x;
	uint32_t         y;
	uint32_t         speed;
}   t_player;

typedef struct s_game
{
    mlx_t		*mlx;
    t_textures  textures;
    t_map		map;
	t_player	player;
}	t_game;

#endif
