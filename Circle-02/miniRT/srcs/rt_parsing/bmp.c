/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:08:59 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 21:52:57 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rgbt_init(t_rgbtriple *trgb, int color)
{
	trgb->rgbtblue = color & 0xFF;
	trgb->rgbtgreen = (color & (0xFF << 8)) >> 8;
	trgb->rgbtred = (color & (0xFF << 16)) >> 16;
}

void	info_init(t_minirt *mini, t_bitmapinfo *info)
{
	info->bisize = 40;
	info->biwidth = mini->scr.wid;
	info->biheight = mini->scr.hei;
	info->biplanes = 1;
	info->bibitcount = 24;
	info->bicompression = 0;
	info->bisizeimage = mini->scr.wid * mini->scr.hei;
	info->bixpelspermeter = mini->scr.wid;
	info->biypelspermeter = mini->scr.hei;
	info->biclrused = 0xffffff;
	info->biclrimportant = 0;
}

void	file_init(t_minirt *mini, t_bitmapfile *file)
{
	int file_size;

	file_size = (3 * mini->scr.hei * mini->scr.wid) + 54;
	file->bftype1 = 'B';
	file->bftype2 = 'M';
	file->bfsize = file_size;
	file->bfreserved1 = 0;
	file->bfreserved2 = 0;
	file->bfoffbits = 54;
}

void	bmpheader(t_minirt *mini, int fd)
{
	t_bitmapfile	file;
	t_bitmapinfo	info;

	file_init(mini, &file);
	info_init(mini, &info);
	write(fd, &file, 14);
	write(fd, &info, 40);
}

void	makebmp(t_minirt *mini)
{
	int			fd;
	int			hdx;
	int			wdx;
	t_rgbtriple	rgbt;

	fd = open("output/minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (fd != -1)
	{
		bmpheader(mini, fd);
		hdx = -1;
		while (++hdx < (mini->scr.hei))
		{
			wdx = -1;
			while (++wdx < (mini->scr.wid))
			{
				rgbt_init(&rgbt, anti(mini, wdx, hdx));
				write(fd, &rgbt, 3);
			}
		}
		close(fd);
		printf_ok("Save Complete!\nfile : output/minirt.bmp\n");
	}
	exit(0);
}
