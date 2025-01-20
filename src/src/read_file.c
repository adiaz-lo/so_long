#include "so_long.h"

char **read_file(int map_fd, t_map map)
{
  char *aux;
  char *map_line;

  map.map = NULL;
  map_line = get_next_line(map_fd);
  while (map_line) {
    aux = *map;
    *(map.map) = ft_strjoin(map.map, map_line);
    if (aux)
      free(aux);
    free(map_line);
    map_line = get_next_line(map_fd);
  }
  return (map.map);
}
