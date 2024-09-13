#include "includes/so_long.h"
#include "includes/player.h"

t_player	*init_player(mlx_t *mlx)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->texture = mlx_load_png("tuxy.png");
	player->image_tuxy = mlx_texture_to_image(mlx, player->texture);
	return (player);
}

void	move_player_right(t_player *player)
{
	player->x += 10;

}

void	move_player_left(t_player *player)
{
	player->x -= 10;

}

void	move_player_down(t_player *player)
{
	player->y += 10;

}

void	move_player_up(t_player *player)
{
	player->y -= 10;

}

void	destroy_player(t_player *player, mlx_t *mlx)
{
	mlx_delete_image(mlx, player->image_tuxy);
	mlx_delete_texture(player->texture);
	free(player);
}

int32_t	main(void)
{
	t_player *player;
	t_mlx_player *mlx_player;
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Tuxy", true);
	player = init_player(mlx);
	mlx_image_to_window(mlx, player->image_tuxy, player->x, player->y);

	mlx_loop(mlx);
	destroy_player(player, mlx);
	mlx_terminate(mlx);

	return(0);
}
