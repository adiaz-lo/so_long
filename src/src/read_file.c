#include "so_long.h"

char **read_file(int map_fd, t_map map)
{
  char *map_line;
  int   i;

  map.map = NULL;
  map_line = get_next_line(map_fd);
  i = 0;
  while (map_line) {
    map.map[i] = ft_strdup(map_line);
    free(map_line);
    map_line = get_next_line(map_fd);
    i++;
  }
  return (map.map);
}
