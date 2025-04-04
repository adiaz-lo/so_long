/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_textures_to_images.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:22:57 by event             #+#    #+#             */
/*   Updated: 2025/04/04 19:22:59 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void convert_textures_to_images(t_game *game) {
  game->textures.player.img =
      mlx_texture_to_image(game->mlx, game->textures.player.path);
  game->textures.floor.img =
      mlx_texture_to_image(game->mlx, game->textures.floor.path);
  game->textures.wall.img =
      mlx_texture_to_image(game->mlx, game->textures.wall.path);
  game->textures.collectable.img =
      mlx_texture_to_image(game->mlx, game->textures.collectable.path);
  game->textures.exit.img =
      mlx_texture_to_image(game->mlx, game->textures.exit.path);
}
