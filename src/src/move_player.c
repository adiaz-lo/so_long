/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:23:46 by event             #+#    #+#             */
/*   Updated: 2025/04/04 19:23:48 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int row, int col)
{
    // printf("Printing debugging %i %i %i %i\n", game->player.x, game->player.y, row, col);
    // printf("Printing debugging %c \n", game->map.map[game->player.y + col][game->player.x + row]);
	if (game->map.map[game->player.y + col][game->player.x + row] != '1')
	{
		game->map.map[game->player.y + col][game->player.x + row] = 'P';
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.x += row;
		game->player.y += col;
		game->textures.player.img->instances[0].x += row * TILE_SIZE;
		game->textures.player.img->instances[0].y += col * TILE_SIZE;
		printf("Testing TILE_SIZE %i %s %i\n", TILE_SIZE, __FILE__,
			__LINE__);
	}
	else
	{
		printf("Testing if condition is broken %s %i\n", __FILE__, __LINE__);
		// printf("Testing TILE_SIZE value %i %s %i\n", TILE_SIZE, __FILE__,
			// __LINE__);
	}
	// printf("Testing width %i %s %i\n", game->mlx->width, __FILE__, __LINE__);
	// printf("Testing the D key pressed %s %i\n", __FILE__, __LINE__);
	// if ((game->player.x + 1 /*game->textures.player.img->width*/) >
	//     (uint32_t)game->mlx->width) {
	//   printf("Testing the D keypress %s %i\n", __FILE__, __LINE__);
	//   return ;
	// }
	// move_player_right(game);
	// printf("x coordinate value: %d\n", game->player.x);
	// printf("Canvas Width: %d\n", game->player.x);
	// printf("Image Width: %d\n", game->player.x);
}
