#include "so_long.h"
// #include <cstdint>

static void malloc_map(t_map *map)
{
    map->map = malloc((map->rows + 1) * sizeof(char *));
    if (!map->map)
        throw_error("Error. Map memory allocation failed");
}

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
    else if (map->columns == 0)
    {
        map->columns = (ft_strlen(line)) - 1;
        printf("Columns: %i \n", map->columns);
        printf("Line is: %s", line);
        free(line);
    }
    i++;
  }
  map->rows = i;
  close(fd);
}

void   trim_new_line(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = ft_strlen(map[i]);
        if (map[i][j - 1] == '\n')
            map[i][j - 1] = '\0';
        i++;
    }
}

char **read_file(char *filename, t_map *map)
{
  char *line;
  uint32_t   i;
  int fd;

  map->map = NULL;
  i = 0;
  calc_map_rows_columns(filename, map);
  printf("Rows: %i \n", map->rows);
  printf("Columns: %i \n", map->columns);
  malloc_map(map);
  fd = open_file(filename);
  //Recheck open failed (redundant)
  while (i < map->rows)
  {
    line = get_next_line(fd);
    //Recheck line not NULL (redundant)
    // map.map[i] = ft_strdup(line);
    map->map[i] = line;
    // free(line);
    i++;
  }
  trim_new_line(map->map);
  map->map[i] = NULL;
  // print_map(map->map);
  printf("Rows: %i \n", map->rows);
  printf("Columns: %i \n", map->columns);
  // print_map(map->map, map->columns, map->rows);
  return (map->map);
}
