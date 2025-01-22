#include "so_long.h"

void calc_map_rows_columns(char *filename, t_map *map) {
  int fd;
  char *line;
  int i;

  fd = open_file(filename);
  map->rows = 0;
  map->columns = 0;
  line = NULL;
  i = 0;
  while (1)
  {
    line = get_next_line(fd);
    if (line == NULL && i == 0)
    {
            throw_error("Error. The map file is empty");
    } else if (line == NULL)
        break ;
    else
    {
        map->columns = (ft_strlen(line)) - 1;
        printf("Columns: %i \n", map->columns);
        printf("Line is: %s", line);
        free(line);
        i++;
    }
  }
  map->rows = i;
  close(fd);
}

char **read_file(char *filename, t_map *map)
{
  // char *map_line;
  // int   i;

  map->map = NULL;
  // i = 0;
  calc_map_rows_columns(filename, map);
  printf("Rows: %i \n", map->rows);
  printf("Columns: %i \n", map->columns);
  // while (1) {
  //   map_line = get_next_line(map_fd);
  //   map.map[i] = ft_strdup(map_line);
  //   free(map_line);
  //   i++;
  // }
  // if (!map_line)
  //     throw_error();
  return (map->map);
}
