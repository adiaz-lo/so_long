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
// t_map init_map(int map_fd);
void throw_error(char *string_error);
char **read_file(char *filename, t_map *map);
void    free_map(char **map);
int open_file(char *file);
void    close_file(int map_fd);
void clean(char **map, int map_fd);
// void malloc_map(t_map *map);
// void print_map(char ** map);
void print_map(char **map, int width, int height);
void check_map_has_minimum_size(t_map *map);
void check_map_rows_length_is_rectangular(t_map *map);
void check_map_horizontal_walls(t_map *map);
void check_map_surrounded_walls(t_map *map);
void check_map_game_elements(t_map *map);
void check_map_wrong(t_map *map);
void    check_map_valid(t_map *map);

#endif
