#include "minirt.h"

void	rgbt_init(t_rgbtriple *trgb, int color)
{
	trgb->rgbtBlue = color & 0xFF;
	trgb->rgbtGreen = (color & (0xFF << 8)) >> 8;
	trgb->rgbtRed = (color & (0xFF << 16)) >> 16;
}

void	info_init(t_minirt *mini, t_bitmapinfo *info)
{
	int temp;

    temp = mini->scr.line_length / 4;
	info->biSize = 40;
	info->biWidth = mini->scr.wid;
	info->biHeight = mini->scr.hei;
	info->biPlanes = 1;
	info->biBitCount = 24;
	info->biCompression = 0;
	info->biSizeImage = mini->scr.wid * mini->scr.hei;
	info->biXPelsPerMeter = mini->scr.wid;
	info->biYPelsPerMeter = mini->scr.hei;
	info->biClrUsed = 0xffffff;
	info->biClrImportant = 0;
}

void	file_init(t_minirt *mini, t_bitmapfile *file)
{
	int file_size;

    file_size = (3 * mini->scr.hei * mini->scr.wid) + 54; // 왜 4?
	file->bfType1 = 'B';
	file->bfType2 = 'M';
	file->bfSize = file_size;
	file->bfReserved1 = 0;
	file->bfReserved2 = 0;
	file->bfOffBits = 54;
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

void makebmp(t_minirt *mini)
{
	int	fd;
	int	hdx;
	int	wdx;
	t_rgbtriple rgbt;
	t_rgbtriple white;
	ft_memset(&white, 0, sizeof(t_rgbtriple));

	fd = open("output/minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (fd != -1)
	{
		bmpheader(mini, fd);
		hdx = -1;
		while (++hdx < (mini->scr.hei))
		{

			wdx = -1;
			while (++wdx < (mini->scr.wid)) {
				rgbt_init(&rgbt, anti(mini, wdx, hdx));
				write(fd, &rgbt, 3);
			}
		}
		close(fd);
		printf_ok("Save Complete!\nfile : output/minirt.bmp\n");
	}
	exit(0);
}
