/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:48:28 by habouiba          #+#    #+#             */
/*   Updated: 2023/01/07 00:08:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"
# include "types.h"

double	**matrix_create_2(void);
double	**matrix_create_3(void);
double	**matrix_create_4(void);
t_bool	matrix_cmp_4(double **m1, double **m2);
t_bool	matrix_cmp_3(double **m1, double **m2);
t_bool	matrix_cmp_2(double **m1, double **m2);
double	**matrix_mul_4(double **m1, double **m2);
double	**matrix_mul_3(double **m1, double **m2);
double	**matrix_mul_2(double **m1, double **m2);
double	**matrix_identity(void);
void	matrix_free_4(void *_m);
void	matrix_free_3(void *_m);
void	matrix_free_2(void *_m);
double	**matrix_transpos_4(double **_m, void (*f)(void *));
double	**matrix_transpos_3(double **_m, void (*f)(void *));
double	**matrix_transpos_2(double **_m, void (*f)(void *));
double	**matrix_sub_4(double **_m, int row, int col);
double	**matrix_sub_3(double **_m, int row, int col);
double	matrix_determinant_2(double **_m);
double	matrix_minor_3(double **m, int row, int col);
double	matrix_cofactor_3(double **m, int row, int col);
double	matrix_cofactor_4(double **m, int row, int col);
double	matrix_determinant_3(double **_m);
double	matrix_determinant_4(double **_m);
double	matrix_minor4(double **m, int row, int col);
t_bool	matrix_is_invertable_n(double **m, int n);
t_bool	matrix_is_invertable_4(double **m);
t_bool	matrix_is_invertable_3(double **m);
t_bool	matrix_is_invertable_2(double **m);
double	**matrix_invert_4(double **m);
double	**matrix_identity_4(void);
double	**matrix_translate_creat_4(t_tuple *t, void (*f)(void *));
t_tuple	*matrix_tuple_3(double **m, t_tuple *t,
			void (*f1)(void *), void (*f2)(void *));
t_tuple	*matrix_tuple_4(double **m, t_tuple *t,
			void (*f1)(void *), void (*f2)(void *));
double	**matrix_scale_4(t_tuple *t, void (*f)(void *));
double	**matrix_rotate_x_4(double angle);
double	**matrix_rotate_y_4(double angle);
double	**matrix_rotate_z_4(double angle);
double	**matrix_mul_4_f(double **m1, double **m2,
			void (*f1)(void *), void (*f2)(void *));
double	__dot_product4(t_tuple *t1, t_tuple *t2,
			void (*f1)(void *), void (*f2)(void *));
#endif
