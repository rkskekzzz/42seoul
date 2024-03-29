/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:18:43 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:18:44 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef enum e_bool {
	FALSE = -1,
	TRUE = 0
}			t_bool;

typedef enum e_dir {
	LEFT,
	RIGHT
}			t_dir;

typedef enum e_msg {
	PICK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_msg;

#endif
