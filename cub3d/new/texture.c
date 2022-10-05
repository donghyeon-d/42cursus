#include "../minilibx_mms_20210621/mlx.h"
#include "cub3d.h"
#include "../ft_libft/libft.h"

// typedef struct	s_img
// {
// 	void	*img;
// 	int		*ad;
// 	int		bpp;
// 	int		len;
// 	int		end;
// 	int		wid;
// 	int		hei;
// } t_img;

// void	ft_img_copy_to_texture(t_info *info, int direct, char *file)
// {
// 	t_img	img;
// 	int		i;
// 	int		j;

// 	img.img = mlx_xpm_file_to_image(info->mlx, info->texture[direct], &img.wid, &img.hei);
// 	img.ad = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
// 	info->texture[direct] = malloc(sizeof(int) * img.len);
// 	i = -1;
// 	while (++i < img.hei)
// 	{
// 		j = -1;
// 		while (++j < img.wid)
// 			info->texture[direct][img.hei * i + j] = img.ad[img.hei * i + j];
// 	}
// 	mlx_destroy_image(info->mlx, img.img);
// }

void	ft_img_copy_to_texture(t_info *info, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(info->mlx, file, &img->wid, &img->hei);
	img->ad = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
}

void	ft_load_texture(t_info *info)
{
	ft_img_copy_to_texture(info, &(info->texture[NORTH]), "../pics/bluestone.xpm");
	ft_img_copy_to_texture(info, &(info->texture[EAST]), "../pics/colorstone.xpm");
	ft_img_copy_to_texture(info, &(info->texture[SOUTH]), "../pics/greystone.xpm");
	ft_img_copy_to_texture(info, &(info->texture[WEST]), "../pics/redbrick.xpm");
}