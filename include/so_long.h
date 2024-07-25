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
}	rectangle_t;
