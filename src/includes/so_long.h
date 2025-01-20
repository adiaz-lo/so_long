#ifndef SO_LONG_H
# define SO_LONG_H

# include "common.h"
# include "player.h"
# include "map.h"

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10000000
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif
# ifndef HEIGHT
#  define HEIGHT 1000
# endif
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif
# ifndef STR_INVALID_MAP_SIZE
#  define STR_INVALID_MAP_SIZE "The map has an error cause it has less than 5 columns or the map has less than 3 rows"
# endif
# ifndef STR_INVALID_HORIZONTAL_FIRST_CELL
#  define STR_INVALID_HORIZONTAL_FIRST_CELL "There's at least 1 row of the map that doesn't start by a wall"
# endif
# ifndef STR_INVALID_HORIZONTAL_LAST_CELL
#  define STR_INVALID_HORIZONTAL_LAST_CELL "There's at least 1 row of the map that doesn't end by a wall"
# endif
# ifndef MAP_EXTENSION
#  define MAP_EXTENSION ".ber"
# endif

t_player *init_player(t_player *mlx_player);
t_map init_map(int map_fd);
void throw_error(char *string_error);
char *read_file(int map_fd);
void    free_map(char **map);
int open_file(char *file);
void    close_file(int map_fd);

#endif
