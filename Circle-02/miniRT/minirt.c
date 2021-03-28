#include <unistd.h>
#include <mlx.h>

int main()
{
	void	*mlx_ptr;
	void	*win_ptr; 
	
	mlx_ptr = mlx_init();	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hellow World!"); 
	mlx_loop(mlx_ptr);
	return (0);
}
