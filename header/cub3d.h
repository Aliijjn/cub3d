/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 13:28:30 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 15:06:26 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/glad/glad.h"
# include "../MLX42/include/KHR/khrplatform.h"
# include "../MLX42/include/lodepng/lodepng.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

# define RED_TEXT "\x1b[31m"
# define RESET "\033[0;37m"

# define SCR_WIDTH 1920
# define SCR_HEIGHT 1080
// REMAKE EVERYTHING AFTER CHANGING ^THESE^ VALUES
# define PI 3.141592653f
# define COLLISION_CHECK 0.2f
# define MOVE_SPEED 0.03f
# define ROTATE_SPEED 0.03f
# define SENSITIVITY 0.001f

# define MM_DIAMETER 5
# define MM_BLOCK_SIZE 32
# define MM_PX_DIA 256
# define MM_MID 176
# define MM_PLAYER 20

enum
{
	ALPHA,
	BLUE,
	GREEN,
	RED
};

typedef union u_rgb
{
	uint32_t	colour;
	uint8_t		val[4];
}	t_rgb;

typedef struct t_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct t_ivector2
{
	int32_t	x;
	int32_t	y;
}	t_ivector2;

typedef struct t_ray_result
{
	float	distance;
	char	side;
	float	index;
}	t_ray_result;

typedef struct t_ray_cast
{
	t_ivector2		map_pos;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	t_vector2		step_dist;
	char			side;
}	t_ray_cast;

typedef struct t_map
{
	char		**grid;
	t_ivector2	size;
	t_vector2	player;
	t_vector2	player_dir;
}	t_map;

typedef struct t_image
{
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*we;
	mlx_image_t	*ea;
	t_rgb		f;
	t_rgb		c;
}	t_image;

typedef struct t_cub3d
{
	t_map		map;
	t_image		image;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_cub3d;

// parse
char		*parse_all(t_cub3d *cub3d, int32_t fd);
char		*parse_map(char **full_file, int index, t_map *map);
bool		check_multiple_nl_in_map(char *str);

// error
void		ft_error(char *msg, mlx_t *mlx, int32_t val);

// tools
char		*str_join(char *dest, char *src);
void		free_2d(char **split);
void		skip_spaces(char **line);
char		*read_file(int fd);
bool		check_if_wall(char **map, t_ivector2 i);

// movement
void		get_user_input(mlx_t *mlx, t_map *map);
void		get_mouse_input(mlx_t *mlx, t_map *map);

// render tools
float		pythag(t_vector2 a);
bool		dot_product(t_vector2 v, float max_len);
t_vector2	copy_vec2(t_vector2 copy);
t_vector2	normalize_vector(t_vector2 vector);
t_vector2	shift_vector(t_vector2 old, float radians);

// render/draw
void		render(t_cub3d cub3d, t_map map, mlx_image_t *img);
void		draw_row(t_cub3d cub3d, mlx_image_t *img, t_ray_result ray, int x);
void		draw_minimap(t_cub3d cub3d, t_map map);
void		display_fps(mlx_t *mlx, char *empty_str);

#endif