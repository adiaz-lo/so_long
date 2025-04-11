#include "so_long.h"

void	check_map(t_game *game)
{
	check_map_wrong(&game->map);
	check_map_valid(&game->map, &game->player);
}