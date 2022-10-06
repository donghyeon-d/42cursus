/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:27:16 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 21:43:11 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define WIN_WID 1280
# define WIN_HEI 720
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.2
# define TRUE 1
# define FALSE 0
# define MAP_TEXTURE 1
# define MAP_COLOR 2
# define MAP_MAP 3

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

#include <stdlib.h>
#include <stdio.h>

// win 에 올릴 결과물, 
// main 그림, texture.xpm 정보, 미니맵, 기타 그림
typedef struct	s_img
{
	void	*img;
	int		*ad;
	int		bpp;
	int		len;
	int		end;
	int		wid;
	int		hei;
} t_img;

typedef struct	s_ray
{
	double	carmera_x; // 카메라 평면에서의 한 x지점
	double	raydir_x; // 광선의 방향 벡터 X
	double	raydir_y; // 광선의 방향 벡터 Y
	double	raydir;
	double	sidedist_x; // 시작지점에서 Y절편 까지의 거리
	double	sidedist_y; // 시작지점에서 X절편 까지의 거리
	double	deltadist_x; // X가 1 증가했을 때 거리
	double	deltadist_y; // Y가 1 증가했을 때 거리
	int		step_x; // 1 or -1
	int		step_y; // 1 or -1
	int		map_x; // 광선이 닿은 벽 x좌표. 처음은 posX
	int		map_y; // 광선이 닿은 벽 y좌표. 처음은 posY
	double	wall_dist; // 광선까지의 거리
	int		wall_side; // 광선이 벽의 어느면에 닿았는지. 0 = x, 1 = y
	double	line_height; // 광선과의 거리를 통해 알게되어 출력할 높이
	int		line_start; // line의 start 지점
	int		line_end; // line의 end 지점
	int		color;  // line의 color
}	t_ray;

// 맵에서 받아온 초기 정보, 다 때려넣기
typedef struct	s_info
{
	double	pos_x; // player 위치 x
	double	pos_y; // player 위치 y
	double	dir_x; // player 보는 방향 x
	double	dir_y; // player 보는 방향 y
	double	plane_x; // player camera 평면 방향 x
	double	plane_y; // player camera 평면 방향 y
	void	*mlx;
	void	*win;
	t_img	*main_img; // win에 올릴 최종 결과물
	double	move_speed; // 이동 속도. 키 입력시 pos 이동 단위
	double	rot_speed; // 방향 회전 속도. 키 입력시 방향회전 단위
	int		**worldmap; // 파싱한 map의 2차원 배열 형태
	int		map_wid; // 맵의 가로 크기 (가장 큰 부분 기준)
	int		map_hei; // 맵의 세로 크기 (맵 줄 수)
	int		floor_color; // 바닥 색
	int		ceiling_color; // 천장 색
	char	*texture_file_name[4]; // NO, EA, SO, WE file name
	t_img	texture[4]; // NO, EA, SO, WE file 의 img 정보
	t_ray	ray;
}	t_info;

void	*ft_malloc(size_t size);

void	error_exit(char *message);
int 	file_check_type(char *filename);
void	file_check(char *filename);

int		what_info(char *file);
void	pass_newline(int fd, char **line);
void	get_map_texture(int fd, char **line,t_info *info);
void	get_map_color(int fd, char **line, t_info *info);
void	get_map_info(char *file, t_info *info);
void	get_map(int fd, char *line, t_info *info);

void	parse(char *file, t_info *info);

char	*get_next_line(int fd);

#endif