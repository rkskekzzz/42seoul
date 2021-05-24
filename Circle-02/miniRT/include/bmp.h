/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:46:43 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 21:50:54 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "minirt.h"
# pragma pack(push, 1)

typedef struct		s_bitmapfile
{
	unsigned char	bftype1;
	unsigned char	bftype2;
	unsigned int	bfsize;
	unsigned short	bfreserved1;
	unsigned short	bfreserved2;
	unsigned int	bfoffbits;
}					t_bitmapfile;

typedef struct		s_bitmapinfo
{
	unsigned int	bisize;
	int				biwidth;
	int				biheight;
	unsigned short	biplanes;
	unsigned short	bibitcount;
	unsigned int	bicompression;
	unsigned int	bisizeimage;
	int				bixpelspermeter;
	int				biypelspermeter;
	unsigned int	biclrused;
	unsigned int	biclrimportant;
}					t_bitmapinfo;

typedef struct		s_rgbtriple
{
	unsigned char	rgbtblue;
	unsigned char	rgbtgreen;
	unsigned char	rgbtred;
}					t_rgbtriple;

# pragma pack(pop)
#endif
