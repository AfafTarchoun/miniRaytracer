/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:46:54 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "libft.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_solution
{
	double		a;
	double		b;
	double		c;
}			t_solution;

typedef struct s_vue
{
	void	*mlx;
	void	*window;
}			t_vue;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;
typedef t_tuple	t_color;

typedef struct s_ray
{
	t_point		*origin;
	t_vector	*dir;
}			t_ray;

typedef enum e_entity_type
{
	SPHERE,
	PLANE,
	CYLINDER
}			t_entity_type;

typedef struct s_entity
{
	t_entity_type	type;
	void			*obj;
}			t_entity;

typedef struct s_material
{
	t_color	*color;
	double	ambient;
	double	deffuse;
	double	specular;
	double	shininess;
}			t_material;

typedef struct s_sphere
{
	t_point		*origin;
	t_point		*coord;
	double		raduis;
	int			id;
	double		**transform;
	double		**inv_transform;
	t_material	*material;
}			t_sphere;

typedef struct s_plane
{
	t_point		*origin;
	t_point		*orient;
	t_material	*material;
	double		**transform;
	double		**inv_transform;
}			t_plane;

typedef struct s_cylinder
{
	t_point		*origin;
	t_point		*coord;
	t_point		*orient;
	t_material	*material;
	double		**inv_transform;
	double		**transform;
	double		diameter;
	double		height;
}			t_cylinder;

typedef struct s_hit
{
	double		t1;
	double		t2;
	t_point		*hitpoint;
	t_entity	*entity;
	t_vector	*eyev;
	t_vector	*norm;
}			t_hit;

typedef struct s_light
{
	t_point		*pos;
	double		intensity;
}			t_light;

typedef struct s_a_light
{
	t_material	*material;
	double		ratio;
}			t_a_light;

typedef struct s_camera
{
	t_point		*origin;
	t_point		*orient;
	int			hsize;
	int			wsize;
	double		psize;
	double		fov;
	double		half_w;
	double		half_h;
	double		**transform;
	double		**inv_transform;
}			t_camera;

typedef struct s_lighting
{
	t_color		*effect;
	t_vector	*lightv;
	t_color		*ambient;
	t_color		*diffuse;
	t_color		*specular;
	t_vector	*reflectv;
}			t_lighting;

typedef struct s_world
{
	t_light		*light;
	t_a_light	*alight;
	t_camera	*camera;
	t_list		*objs;
}			t_world;

#endif // MINIRT_TYPES_H
