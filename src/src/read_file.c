#include "so_long.h"

int open_map(char *map_name)
{
    int map_fd;

    map_fd = open(map_name, O_RDONLY);
    if (map_fd == -1)
      throw_error("The map couldn't be open successfully");
   /*Initialize the map, to null */
   /*Read map (iterate the file), save it in the matrix & print it, test it with different maps*/
   /*Create function debug(char **map), it iterates it and print it*/

   return (map_fd);
}

char *read_file(int map_fd)
{
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
