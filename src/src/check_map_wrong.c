#include "so_long.h"

// void check_map_has_minimum_size(t_map *map) {
//   if ((map->map->rows >= 3 && map->map->columns >= 5) ||
//       (map->map->rows >= 5 && map->map->columns >= 3))
//     return;
//   else
//     throw_error(STR_INVALID_MAP_SIZE);
// }

void check_map_rows_length_is_rectangular(t_map *map) {
  unsigned int  x;
  unsigned int  y;
  unsigned int  length;

  y = 0;
  length = ft_strlen(map->map[y]);
  while (y < map->y) {
      x = ft_strlen(map->map[y]);
    if (x != length)
      throw_error("The map has different length in its rows");
    y++;
  }
}

void check_map_horizontal_walls(t_map *map) {
  int i;
  int j;

  i = 0;
  while (map->map[i]) {
    j = 0;
    if (map->map[i][0] != '1')
      throw_error(STR_INVALID_HORIZONTAL_FIRST_CELL);
    while (map->map[i][j])
      j++;
    if (map->map[i][j - 1] != '1')
      throw_error(STR_INVALID_HORIZONTAL_LAST_CELL);
    i++;
  }
}

void check_map_surrounded_walls(t_map *map) {
  int i;

  i = 0;
  while (map->map[0][i] == '1')
    i++;
  if (map->map[0][i] != 0)
    throw_error("All the cells of the first row of the map aren't walls");
  i = 0;
  while (map->map[map->y - 1][i] == '1')
    i++;
  if (map->map[map->y - 1][i] != 0)
    throw_error("All the cells of the last row of the map aren't walls");
  check_map_horizontal_walls(map);
}

void check_map_game_elements(t_map *map) {
  int i;
  int j;
  int32_t player_number;
  int32_t exit_number;
  int32_t collectable_number;

  player_number = 0;
  exit_number = 0;
  collectable_number = 0;
  i = 0;
  while (map->map[i]) {
    j = 0;
    while (map->map[i][j]) {
      if (map->map[i][j] == 'P')
        player_number += 1;
      else if (map->map[i][j] == 'E')
        exit_number += 1;
      else if (map->map[i][j] == 'C')
        collectable_number += 1;
      else if (map->map[i][j] != '0' &&
               map->map[i][j] != '1' &&
               map->map[i][j] != '\n')
        throw_error("The map has something that doesn't belong there");
      j++;
    }
    i++;
  }
  if (player_number != 1 || exit_number != 1 || collectable_number < 1)
    throw_error("The map isn't correct in terms of map elements");
}

void check_map_wrong(t_map *map) {
  // check_map_has_minimum_size(map);
  check_map_rows_length_is_rectangular(map);
  check_map_surrounded_walls(map);
  check_map_game_elements(map);
}
