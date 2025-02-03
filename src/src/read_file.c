#include "so_long.h"
// #include <cstdint>

static void malloc_map(t_map *map)
{
    map->map = malloc((map->y + 1) * sizeof(char *));
    if (!map->map)
        throw_error("Error. Map memory allocation failed");
}

void calc_map_rows_columns(char *filename, t_map *map) {
  int fd;
  char *line;
  int i;

  fd = open_file(filename);
  map->y = 0;
  map->x = 0;
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
    else if (map->x == 0)
    {
        map->x = (ft_strlen(line)) - 1;
        printf("Columns: %i \n", map->x);
        printf("Line is: %s", line);
        free(line);
    }
    i++;
  }
  map->y = i;
  close(fd);
}

void   trim_new_line(char **map)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(map[i]);
    while (map[i])
    {
            if (map[i][j - 1] == '\n')
                map[i][j - 1] = '\0';
                else if (map[i][j - 1] == '\0')
                return ;
        i++;
    }
}

char **read_file(char *filename, t_map *map)
{
  char *line;
  int32_t   i;
  int fd;

  map->map = NULL;
  i = 0;
  calc_map_rows_columns(filename, map);
  printf("Rows: %i \n", map->y);
  printf("Columns: %i \n", map->x);
  malloc_map(map);
  fd = open_file(filename);
  //Recheck open failed (redundant)
  while (i < map->y)
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
  printf("Rows: %i \n", map->y);
  printf("Columns: %i \n", map->x);
  // print_map(map->map, map->x, map->y);
  return (map->map);
}
