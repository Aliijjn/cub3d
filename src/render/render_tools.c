/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_tools.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/26 11:45:29 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 12:13:38 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

float	pythag(t_vector2 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y));
}

bool	dot_product(t_vector2 v, float max_len)
{
	return (v.x * v.x + v.y * v.y < max_len * max_len);
}

t_vector2	copy_vec2(t_vector2 copy)
{
	t_vector2	result;

	result = (t_vector2){copy.x, copy.y};
	return (result);
}

t_vector2	normalize_vector(t_vector2 vector)
{
	float		length;
	t_vector2	result;

	length = pythag(vector);
	if (length == 0)
	{
		printf("Divide by 0 prevented\n");
		return (vector);
	}
	result.x = vector.x / length;
	result.y = vector.y / length;
	return (result);
}

t_vector2	shift_vector(t_vector2 old, float radians)
{
	t_vector2	new;

	new.x = old.x * cos(radians) - old.y * sin(radians);
	new.y = old.x * sin(radians) + old.y * cos(radians);
	return (new);
}
