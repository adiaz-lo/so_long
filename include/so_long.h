#include "../lib/MLX42/include/MLX42/MLX42.h"

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */
/*typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;*/

typedef struct color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
}	color_t;


typedef struct background
{
	int32_t	size[2]; //Width & height array
	color_t	color;	//Background color
}	background_t;

/**
 * Struct to define a rectangle
 *
 *
 */
typedef	struct	rectangle
{
	int32_t	size[2]; //Width & height array
	int32_t	x;
	int32_t	y;
	color_t	color;
	mlx_image_t	*img; //Rectangle itself as image to use it in the program
}	rectangle_t;

/**
 *
 */
typedef	struct	game
{
//	mlx_image_t	*canvas;
	mlx_t		*mlx;
	rectangle_t	*canvas;
	rectangle_t	*img;
}	game_t;
