#include "so_long.h"

void    find_player_position(t_map *map, t_player player)
{
    int i;
    int j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
            {
                player.x = j;
                player.y = i;
                printf("Player position is: %d-%d", player.y, player.x);
                return ;
            }
            j++;
        }
        i++;
    }
}

void    floodFillRecursive(t_map *map, int32_t x, int32_t y, t_player player) {
if (x < 0 || x >= map->x || y < 0 || y >= map->y)
        return;

    floodFillRecursive(map, x + 1, y, player);
    floodFillRecursive(map, x - 1, y, player);
    floodFillRecursive(map, x, y + 1, player);
    floodFillRecursive(map, x, y - 1, player);

const uint32_t startX = 0;
const uint32_t startY = 0;

floodFillRecursive(map, startX, startY, player);
printf("Flood-Fill Print Test\n");
}

void check_map_valid(t_map *map, t_player player)
{
    find_player_position(map, player);
    floodFillRecursive(map, player.x, player.y, player);
}
