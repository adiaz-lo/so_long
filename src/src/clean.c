#include "so_long.h"

void    clean(char **map, int map_fd)
{
    free_map(map);
    close(map_fd);
}
