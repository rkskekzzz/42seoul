#include "minirt.h"

static void write_bmp_h(t_minirt *mini, int fd)
{
	unsigned char bmp_h[54];
	int file_size;

	ft_memset(bmp_h, 0, 54);
	file_size = 4 * mini->scr.hei * mini->scr.wid + 54;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (unsigned char)file_size;
	bmp_h[3] = (unsigned char)(file_size >> 8);
	bmp_h[4] = (unsigned char)(file_size >> 16);
	bmp_h[5] = (unsigned char)(file_size >> 24);
	bmp_h[10] = 54; //file header + info header 크기이자 오프셋//-s->y;//음수면 이미지 상하 반전
	bmp_h[14] = 40; //info header 크기
	bmp_h[18] = (unsigned char)mini->scr.wid;
	bmp_h[19] = (unsigned char)((int)mini->scr.wid >> 8);
	bmp_h[20] = (unsigned char)((int)mini->scr.wid >> 16);
	bmp_h[21] = (unsigned char)((int)mini->scr.wid >> 24);
	bmp_h[22] = (unsigned char)mini->scr.hei;
	bmp_h[23] = (unsigned char)((int)mini->scr.hei >> 8);
	bmp_h[24] = (unsigned char)((int)mini->scr.hei >> 16);
	bmp_h[25] = (unsigned char)((int)mini->scr.hei >> 24);
	bmp_h[26] = 1;
	bmp_h[27] = 32; //픽셀당 비트 수
	write(fd, bmp_h, 54);

}

// static void write_bmp_i(t_minirt *mini, int fd)
// {//색깔 채울 때 s->img.addr[pix_y * s->img.len / 4 + pix_x] 썼던 걸 기억하자
// 	char	*pix_arr;
// 	int		img_size;
// 	int		i;
// 	int		j;

// 	if (!(pix_arr = (char*)malloc(sizeof(char) * s->img.len * s->y)))
// 		check_error_exit(s, 6);
// 	img_size = s->x * s->y;
// 	i = -1;
// 	j = -1;
// 	while (++i < img_size)
// 	{
// 		pix_arr[++j] = s->img.addr[i] & 255;//b
// 		pix_arr[++j] = (s->img.addr[i] & 255 << 8) >> 8;//g
// 		pix_arr[++j] = (s->img.addr[i] & 255 << 16) >> 16;//r
// 		pix_arr[++j] = 0;//투명도 비트는 안 쓰니까 0
// 	}
// 	write(fd, pix_arr, s->img.len * s->y);//동적 할당해서 이미지 담아놓고 한번에 파일에 쓰기
// 	free(pix_arr);
// }//내 코드서 minilibx 최신 버전의 mlx_get_data_arrd() 호출했을 때 img.len 값이 2048. 다른 분은 2000


int makebmp(t_minirt *mini)
{
	int fd;
	
	fd = open("output/minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC,0744);
	if (fd == -1)
		return (ERROR);
	write_bmp_h(mini, fd);
	// write_bmp_i(mini, fd);
	close(fd);
	printf_ok("Save Complete!\nfile : output/minirt.bmp\n");
    exit(0);
}