#include "minirt.h"

void    write_bmp_header(t_minirt *mini, int fd)
{
    unsigned char bmp_h[54];
    int file_size;
    int temp;

    ft_memset(bmp_h, 0, 54);
    temp = mini->scr.line_length / 4;
    file_size = 4 * mini->scr.hei * temp + 54;
    bmp_h[0] = 'B';
    bmp_h[1] = 'M';
    bmp_h[2] = (unsigned char)file_size;
    bmp_h[3] = (unsigned char)(file_size >> 8);
    bmp_h[4] = (unsigned char)(file_size >> 16);
    bmp_h[5] = (unsigned char)(file_size >> 24);
    bmp_h[10] = 54;
    bmp_h[14] = 40;
    bmp_h[18] = (unsigned char)temp;
    bmp_h[19] = (unsigned char)(temp >> 8);
    bmp_h[20] = (unsigned char)(temp >> 16);
    bmp_h[21] = (unsigned char)(temp >> 24);
    bmp_h[22] = (unsigned char)mini->scr.hei;
    bmp_h[23] = (unsigned char)((int)mini->scr.hei >> 8);
    bmp_h[24] = (unsigned char)((int)mini->scr.hei >> 16);
    bmp_h[25] = (unsigned char)((int)mini->scr.hei >> 24);
    bmp_h[26] = 1;
    bmp_h[28] = 32;
    write(fd, bmp_h, 54);
}


static void write_bmp_i(t_minirt *mini, int fd)
{
	char	*pix_arr;
	int		img_size;
	int		i;
	int		j;

	pix_arr = malloc(sizeof(char) * mini->scr.line_length * mini->scr.hei);
	if (!pix_arr)
		printf_error("malloc");
	img_size = mini->scr.wid * mini->scr.hei;
	i = -1;
	j = -1;
	while (++i < img_size)
	{
		pix_arr[++j] = mini->curr_cam->img_addr[i] & 255;
		pix_arr[++j] = (mini->curr_cam->img_addr[i] & 255 << 8) >> 8;
		pix_arr[++j] = (mini->curr_cam->img_addr[i] & 255 << 16) >> 16;
		pix_arr[++j] = 0;
	}
	write(fd, pix_arr, mini->scr.line_length * mini->scr.hei);
	free(pix_arr);
}


int makebmp(t_minirt *mini)
{
	int fd;
	
	fd = open("output/minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC,0744);
	if (fd != -1)
	{
		write_bmp_h(mini, fd);
		write_bmp_i(mini, fd);
		close(fd);
		printf_ok("Save Complete!\nfile : output/minirt.bmp\n");
	}
    exit(0);
}