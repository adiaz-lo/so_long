/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:24:20 by event             #+#    #+#             */
/*   Updated: 2025/04/04 19:24:22 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <cstdio>

// void print_map(char **map) {
//   int i;
//   int j;

//   i = 0;
//   while (map[i]) {
//     j = 0;
//     while (map[i][j]) {
//       printf("%c", map[i][j]);
//       j++;
//     }
//     printf("\n");
//     i++;
//   }
// }
#define COLOR_RESET "\033[0m"
#define COLOR_PLAYER "\033[1;34m" // Blue
#define COLOR_COLLECTIBLE "\033[1;32m" // Green
#define COLOR_WALL "\033[1;31m" // Red
#define COLOR_EXIT "\033[1;33m" // Yellow
#define COLOR_EMPTY "\033[1;37m" // White
#define COLOR_TERRAIN "\033[1;36m" // Cyan

void print_map(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        // printf("Width value is: %i\n", width);
        for (int j = 0; j < width; j++)
        {
            char tile = map[i][j];
            switch (tile)
            {
                case 'P':
                    printf(COLOR_PLAYER "P" COLOR_RESET);
                    break;
                case 'C':
                    printf(COLOR_COLLECTIBLE "C" COLOR_RESET);
                    break;
                case '1':
                    printf(COLOR_WALL "1" COLOR_RESET);
                    break;
                case 'E':
                    printf(COLOR_EXIT "E" COLOR_RESET);
                    break;
                case '0':
                    printf(COLOR_EMPTY "0" COLOR_RESET);
                    break;
                case 'F':
                    printf(COLOR_TERRAIN "F" COLOR_RESET);
                    break;
                default:
                    printf("%c", tile);
                    break;
            }
        }
        printf("\n");
    }
}
