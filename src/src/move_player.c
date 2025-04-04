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


void    move_player(t_game *game, int row, int col)
{
    // if (row == 1 && col == 0)
    if (game->map.map[game->player.x + row][game->player.y + col] != 1)
        {
            game->map.map[game->player.x + row][game->player.y + col] = 'P';
            game->player.x += row;
            game->player.y += col;
        }


    // printf("Testing width %i %s %i\n", game->mlx->width, __FILE__, __LINE__);
    // printf("Testing the D key pressed %s %i\n", __FILE__, __LINE__);
    // if ((game->player.x + 1 /*game->textures.player.img->width*/) >
    //     (uint32_t)game->mlx->width) {
    //   printf("Testing the D keypress %s %i\n", __FILE__, __LINE__);
    //   return;
    // }
    // move_player_right(game);
    // printf("x coordinate value: %d\n", game->player.x);
    // printf("Canvas Width: %d\n", game->player.x);
    // printf("Image Width: %d\n", game->player.x);
}
