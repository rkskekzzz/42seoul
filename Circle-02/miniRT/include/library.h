/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:34 by ycha              #+#    #+#             */
/*   Updated: 2021/05/16 17:25:25 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H
# include "minirt.h"

// lib1.c
int trgb(int t, int r, int g, int b);
double r_num(int anti, int min, int max);
double clamp(double n, double min, double max);
double ft_min(double a, double b);
double ft_max(double a, double b);
double ft_abs(double n);

//lib2.c
int ft_arrsize(char **arr);
int	ft_strncmp(const char *s1, const char *s2);
int	ft_strchr(const char *s, int c);
int ft_strlen(char *str);
void *ft_memset(void *dest, int value, size_t size);

//lib2.c to lib3.c
int ft_isspace(char c);
int ft_isdigit(char c);
int ft_isnum(char *str);
int ft_atoi(char *line);
double ft_atod(double *f, char *line);

//lib3.c
char **ft_split(char const *s, char *delim);
char **ft_free_split(char **s, int i);
#endif
