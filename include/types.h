/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:46:54 by habouiba          #+#    #+#             */
/*   Updated: 2022/12/15 08:36:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#include "../libs/libft/libft.h"

typedef struct s_image
{
	void *img;
	char *addr;
	int   bits_per_pixel;
	int   line_length;
	int   endian;
} t_image;

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_vue
{
	void *mlx;
	void *window;
} t_vue;

typedef struct s_tuple
{
	float x;
	float y;
	float z;
	float w;
} t_tuple;

typedef t_tuple t_point;
typedef t_tuple t_vector;
typedef t_tuple t_color;

typedef struct s_ray
{
	t_point  *origin;
	t_vector *dir;
} t_ray;

typedef enum e_entity_type
{
	SPHERE,
	PLANE,
	CYLINDER
} t_entity_type;

typedef struct s_entity
{
	t_entity_type type;
	void	     *obj;
} t_entity;

typedef struct s_material
{
	t_color *color;
	double    ambient;
	double    deffuse;
	double    specular;
	double    shininess;
} t_material;

typedef struct s_sphere
{
	t_point    *origin;
	t_point		*coord;
	float       raduis;
	int         id;
	t_vector   *normal;
	t_vector *hitpoint;
	float     **transform;
	t_material *material;
} t_sphere;

typedef struct s_plane
{
	t_point	*origin;
	t_point *orient;
	t_material *material;
	float     **transform;
} t_plane;

typedef struct s_cylinder
{
	t_point	*origin;
	t_point *coord;
	t_point *orient;
	t_material *material;
	float     **transform;
	double diameter;
	double height;
} t_cylinder;

typedef struct s_hit
{
	float     t1;
	float     t2;
	t_entity *entity;
} t_hit;

typedef struct s_light
{
	t_point	*pos;
	double intensity;
} t_light;

typedef struct s_a_light
{
	t_material *material;
	double ratio;
} t_a_light;

typedef struct s_camera
{
	t_point	*origin;
	t_point	*orient;
	int     hsize;
	int     wsize;
	float   psize;
	double   fov;
	float   half_w;
	float   half_h;
	float **transform;
} t_camera;

typedef struct s_world
{
	t_light   *light;
	t_a_light *alight;
	t_camera *camera;
	t_list    *objs;
} t_world;

#endif // MINIRT_TYPES_H
