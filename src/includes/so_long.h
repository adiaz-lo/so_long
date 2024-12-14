#ifndef SO_LONG_H
#   define SO_LONG_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10000000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "player.h"
# include "map.h"
# include "../Libft/includes/libft.h"
# include "../Libft/includes/get_next_line.h"


# ifndef WIDTH
#  define WIDTH 1000
# endif
# ifndef HEIGHT
#  define HEIGHT 1000
# endif
# ifndef TILE_WIDTH
#  define TILE_WIDTH 64
# endif
# ifndef TILE_HEIGHT
#  define TILE_HEIGHT 64
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


#endif
