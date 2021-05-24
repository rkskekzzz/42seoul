#ifndef BMP_H
# define BMP_H
# include "minirt.h"
# pragma pack(push, 1)

typedef struct s_bitmapfile
{
    unsigned char	bfType1;
	unsigned char	bfType2;
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
} t_bitmapfile;

typedef struct s_bitmapinfo
{
    unsigned int   biSize;
    int            biWidth;
    int            biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} t_bitmapinfo;

typedef struct s_rgbtriple
{
    unsigned char rgbtBlue;
    unsigned char rgbtGreen;
    unsigned char rgbtRed;
    unsigned char a;
} t_rgbtriple;

# pragma pack(pop)
#endif
