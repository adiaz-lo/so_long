/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:21:39 by event             #+#    #+#             */
/*   Updated: 2025/04/04 19:21:44 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player_position(t_map *map, t_player *player) {
  int i;
  int j;

  i = 0;
  while (map->map[i]) {
    j = 0;
    while (map->map[i][j]) {
      if (map->map[i][j] == 'P') {
        player->x = j;
        player->y = i;
        printf("Player position is: %d-%d", player->y, player->x);
        return;
      }
      j++;
    }
    i++;
  }
}

void floodFillRecursive(char **map, int32_t x, int32_t y, t_player *player) {
  // const uint32_t startX = 0;
  // const uint32_t startY = 0;

  if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == 0)
    return;
  if (map[y][x] == 'F' || map[y][x] == '1')
    return;
  map[y][x] = 'F';
  floodFillRecursive(map, x + 1, y, player);
  floodFillRecursive(map, x - 1, y, player);
  floodFillRecursive(map, x, y + 1, player);
  floodFillRecursive(map, x, y - 1, player);

  // floodFillRecursive(map, startX, startY, player);
  // printf("Flood-Fill Print Test\n");
}

char **copy_map(char **map, int32_t width, int32_t height) {
  char **map_copy;
  int y;

  map_copy = malloc(sizeof(char *) * (width + 1) * (height + 1));
  y = 0;
  while (y < height) {
    map_copy[y] = ft_strdup(map[y]);
    y++;
  }
  map_copy[y] = NULL;
  return (map_copy);
}

void check_map_flooded(char **map_flooded) {
  int y;
  int x;

  y = 0;
  while (map_flooded[y] != NULL) {
    x = 0;
    while (map_flooded[y][x] != '\0') {
      if (map_flooded[y][x] != 'F' && map_flooded[y][x] != '1' &&
          map_flooded[y][x] != '0')
        throw_error("The map is not valid, this means that it can \
                        not be completed");
      x++;
    }
    y++;
  }
}

void check_map_valid(t_map *map, t_player *player) {
  char **map_copy;

  map_copy = copy_map(map->map, map->x, map->y);
  find_player_position(map, player);
  floodFillRecursive(map_copy, player->x, player->y, player);
  // print_map(map_copy, map->x, map->y);
  check_map_flooded(map_copy);
  // print_map(map_copy, map->y, map->x);
  double_free(map_copy);
  printf("Player position is: %d-%d\n", player->y, player->x);
}
