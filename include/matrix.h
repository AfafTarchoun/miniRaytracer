/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:48:28 by habouiba          #+#    #+#             */
/*   Updated: 2022/11/25 11:10:44 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include "libft.h"
#include "types.h"

float **matrix_create_2();
float **matrix_create_3();
float **matrix_create_4();
t_bool  matrix_cmp_4(float **m1, float **m2);
t_bool  matrix_cmp_3(float **m1, float **m2);
t_bool  matrix_cmp_2(float **m1, float **m2);
float **matrix_mul_4(float **m1, float **m2);
float **matrix_mul_3(float **m1, float **m2);
float **matrix_mul_2(float **m1, float **m2);
float **matrix_identity(void);
void    matrix_free_4(void *_m);
void    matrix_free_3(void *_m);
void    matrix_free_2(void *_m);
float **matrix_transpos_4(float **_m, void (*f)(void *));
float **matrix_transpos_3(float **_m, void (*f)(void *));
float **matrix_transpos_2(float **_m, void (*f)(void *));
float **matrix_sub_4(float **_m, int row, int col);
float **matrix_sub_3(float **_m, int row, int col);
float   matrix_determinant_2(float **_m);
float   matrix_minor_3(float **m, int row, int col);
float   matrix_cofactor_3(float **m, int row, int col);
float   matrix_cofactor_4(float **m, int row, int col);
float   matrix_determinant_3(float **_m);
float   matrix_determinant_4(float **_m);
float   matrix_minor4(float **m, int row, int col);
t_bool  matrix_is_invertable_n(float **m, int n);
t_bool  matrix_is_invertable_4(float **m);
t_bool  matrix_is_invertable_3(float **m);
t_bool  matrix_is_invertable_2(float **m);
float **matrix_invert_4(float **m);
float **matrix_identity_4(void);
float **matrix_translate_creat_4(t_tuple *t, void (*f)(void *));
t_tuple *matrix_tuple_3(float **m, t_tuple *t, void (*f1)(void *), void (*f2)(void *));
t_tuple *matrix_tuple_4(float **m, t_tuple *t, void (*f1)(void *), void (*f2)(void *));
float **matrix_scale_4(t_tuple *t, void (*f)(void *));
float **matrix_rotate_x_4(float angle);
float **matrix_rotate_y_4(float angle);
float **matrix_rotate_z_4(float angle);
float **matrix_mul_4_f(float **m1, float **m2, void (*f1)(void *), void (*f2)(void *));
#endif
