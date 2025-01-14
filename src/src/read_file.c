#include "so_long.h"

char *read_file(int map_fd) {
  char *map;
  char *aux;
  char *map_line;

  map = NULL;
  map_line = get_next_line(map_fd);
  while (map_line) {
    aux = map;
    map = ft_strjoin(map, map_line);
    if (aux)
      free(aux);
    free(map_line);
    map_line = get_next_line(map_fd);
  }
  return (map);
}
