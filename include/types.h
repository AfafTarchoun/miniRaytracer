/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:46:54 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/20 02:19:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
# include "../libs/libft/libft.h"

typedef struct s_vue
{
	void *mlx;
	void *window;
} t_vue;

typedef struct s_vec3
{
	double x;
	double y;
	double z;
} t_vec3;

typedef struct s_ray
{
	t_vec3 origin;
	t_vec3 direction;
	double t;
} t_ray;

typedef struct s_image
{
	void *img;
	char *addr;
	int   bits_per_pixel;
	int   line_length;
	int   endian;
} t_image;

typedef struct s_camera
{
	t_vec3 *origin;
	t_vec3 *horizontal;
	t_vec3 *vertical;
	t_vec3 *lower_left_corner;
	double  focal_length;
	double  view_port_hight;
	double  view_port_width;
} t_camera;

typedef enum e_shape_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	UNKNOWN
} t_shape_type;

typedef struct s_shape
{
	t_shape_type type;
	void        *attr;
} t_shape;

typedef struct s_ambient_light_attr
{
	t_vec3 color;
	double ratio;
} t_ambient_light_attr;

typedef struct s_camera_attr
{
	t_vec3 coordinates;
	t_vec3 orientation;
	double fov;
} t_camera_attr;

typedef struct s_light_attr
{
	t_vec3 coordinates;
	double brightness;
} t_light_attr;

typedef struct s_sphere_attr
{
	t_vec3 coordinates;
	t_vec3 color;
	double diameter;
} t_sphere_attr;

typedef struct s_plane_attr
{
	t_vec3 coordinates;
	t_vec3 orientation;
	t_vec3 color;
} t_plane_attr;

typedef struct s_cylinder_attr
{
	t_vec3 coordinates;
	t_vec3 orientation;
	t_vec3 color;
	double diameter;
	double height;
} t_cylinder_attr;

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_scene
{
	t_camera_attr        *camera;
	t_light_attr         *light;
	t_ambient_light_attr *ambient_light;
	t_list	           *objects;
} t_scene;

typedef struct s_intersection
{
	double   t1;
	double   t2;
	int      x;
	int      y;
	t_shape *shape;
} t_intersection;

#endif // MINIRT_TYPES_H
