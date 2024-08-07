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
	int8_t	red;
	int8_t	green;
	int8_t	blue;
	int8_t	alpha;
}	color_t;

/**
 * Struct to define a rectangle
 *
 *
 */
typedef	struct	rectangle
{
	int32_t	width;
	int32_t	height;
	int32_t	x;
	int32_t	y;
	color_t	color;
}	rectangle_t;

/**
 *
 */
typedef	struct	game
{
	mlx_image_t	*canvas;
	rectangle_t	*img;
}	game_t;
