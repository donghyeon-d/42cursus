#include "../minilibx_mms_20210621/mlx.h"
#include "cub3d.h"
#include "../ft_libft/libft.h"

void	ft_img_copy_to_texture(t_info *info, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(info->mlx, file, &img->wid, &img->hei);
	img->ad = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
}

void	ft_load_texture(t_info *info)
{
	ft_img_copy_to_texture(info, (info->texture[NORTH]), "../pics/bluestone.xpm");
	ft_img_copy_to_texture(info, (info->texture[EAST]), "../pics/colorstone.xpm");
	ft_img_copy_to_texture(info, (info->texture[SOUTH]), "../pics/greystone.xpm");
	ft_img_copy_to_texture(info, (info->texture[WEST]), "../pics/redbrick.xpm");
}