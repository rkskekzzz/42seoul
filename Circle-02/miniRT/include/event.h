/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:34 by ycha              #+#    #+#             */
/*   Updated: 2021/05/24 21:46:29 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "minirt.h"

typedef struct s_screen		t_screen;

int exit_hook(void);
int	key_hook(int keycode, t_minirt *mini);

#endif
