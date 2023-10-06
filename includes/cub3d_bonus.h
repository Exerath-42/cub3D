/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:14 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 12:12:50 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define NORTH 3
# define SOUTH 4
# define EAST 5
# define WEST 6
# define FLOOR 7
# define CEILING 8
# define MAP 42

# define WHITE 16777215
# define GREY 8355711
# define BLACK 0
# define RED 16711680

# define ESCAPE 65307

# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define WINDOW_W 800
# define WINDOW_H 600

# define SPEED 0.04
# define TURN 0.02

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_file
{
	char			*line;
	int				index;
	int				len;
	int				type;
	struct s_file	*next;
	struct s_file	*prev;
}			t_file;

typedef struct s_mapdata
{
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	struct s_file	*file;
	int				floor_color;
	int				ceiling_color;
	int				rowsize;
	int				colsize;
	char			**map;
}					t_mapdata;

typedef struct s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			h;
}				t_ray;

typedef struct s_hit
{
	double			x;
	double			y;
	double			d;
	char			side;
}				t_hit;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	orientation_x;
	double	orientation_y;
	double	top_angle;
}			t_player;

typedef struct t_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_key;

typedef struct t_sprite
{
	int		size_x;
	int		size_y;
	t_image	*frame1;
	t_image	*frame2;
	t_image	*frame3;
	t_image	*frame4;
	t_image	*frame5;
	t_image	*frame6;
	t_image	*frame7;
}			t_sprite;

typedef struct s_door
{
	int		x;
	int		y;
	int		anim;
	t_image	*door;
}		t_door;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_image			*image;
	t_mapdata		*data;
	t_player		*player;
	int				tex_size_x;
	int				tex_size_y;
	t_image			*tex_north;
	t_image			*tex_south;
	t_image			*tex_east;
	t_image			*tex_west;
	t_ray			ray;
	t_hit			hit;
	t_key			*key;
	int				loop;
	t_image			*door;
	t_sprite		*doors;
	int				nb_doors;
	int				ongoing;
	t_door			*anim;
}					t_game;

/* check_file.c */
t_file		*ft_check_file(t_mapdata *data, char *filename);
t_file		*ft_read_file(char *filename);
int			ft_analyse_elem(t_mapdata *data, t_file *node, char **elem, int *i);

/* check_file2.c */
int			check_id(char *first);
int			check_texture(char **element, t_mapdata *data, int flag);
int			check_texture_2(char **element, t_mapdata *data, int flag);

/* cleaning_bonus.c */
void		ft_free_list(t_file *lst);
void		ft_free_tab(char **tab);
void		ft_clean_data(t_mapdata *data);
void		ft_clean_bonus(t_game *game);
void		ft_clean_bonus2(t_game *game);

/* colors.c */
int			check_id_colors(char **element, t_mapdata *data, int flag);
int			ft_getcolor(char *info);
int			ft_rgb_to_int(int red, int green, int blue);

/* draw.c */
void		floor_ceiling_draw(t_game *game);

/* exit_bonus.c */
void		ft_clean_images(t_game *game);
void		finish(int n);
int			ft_clean_exit(t_game *game, int flag);

/* ft_atoi.c - ft_ncmp_dup.c - ft_split.c */
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strdup_padding(const char *src, int len);
char		**ft_split(char const *s, char c);

/* get_map_bonus.c */
char		**ft_get_map(t_file	*file);
char		**ft_extract_map(t_file *start, int len);
int			ft_check_map(char **map);
int			ft_check_tile(char **map, int x, int y, int *player);
int			ft_surrounded(char	**map, int x, int y);

/* hooks_bonus.c */
void		hooks(t_game *game);
int			closer(t_game *game);
int			key_press(int key, t_game *game);
int			key_release(int key, t_game *game);
int			refresh(t_game *game);

/* hooks2_bonus.c */
int			ft_anim_door(t_game *game);
void		anim_door2(t_game *game, int x, int y, int flag);
int			ft_change_door_status(t_game *game, int i, int flag);

/* hooks3_bonus.c */
void		ft_open(t_game *game);
void		ft_close(t_game *game);
void		ft_open_door(t_game *game, int i);
void		ft_close_door(t_game *game, int i);

/* image.c */
t_game		*init_win(t_mapdata *data, t_player *player);
t_image		*init_image(void *mlx, t_game *game);
void		ft_putpixel(t_image *data, int x, int y, int color);
t_door		*ft_find_doors(t_game *game, char **map);
void		ft_track_doors(char **map, t_door *tab);

/* init_bonus.c */
int			ft_init_bonus(t_game *game);

/* init_game_bonus.c */
t_game		*ft_init_game(void);
int			ft_init_hooks(t_game *game);
int			ft_init_tex(t_game *game, t_mapdata *data);
int			ft_init_tex2(t_game *game, t_mapdata *data);

/* minimap.c */
void		ft_draw_minimap(t_game *game, char **map, int posx, int posy);
int			ft_start(int position);
void		ft_draw_tile(t_game *game, int flag, int x, int y);

/* moves_bonus.c */
void		ft_strafe(t_game *game, double c);
void		ft_move(t_game *game, double c);
void		ft_rotate(t_game *game, double c);

/* parsing_utils.c */
void		ft_lstadd(t_file **alst, t_file *new);
t_file		*ft_lstnew(char *line);
t_file		*ft_lstlast_mod(t_file *lst);
int			ft_lstsize(t_file *lst);
int			ft_strchr(char *str, char c);

/* parsing.c */
t_mapdata	*parsing(int argc, char **argv);
t_mapdata	*ft_get_data(char *filename);
int			ft_check_arg(int argc, char *arg);
void		ft_init_data(t_mapdata *data);

/* player.c */
void		ft_init_player(t_player *player, t_mapdata *data);

/* raycaster_bonus.c */
void		ft_raycaster(t_game *game);
void		ft_screen(t_game *game);
void		ft_ray(t_game *game);
void		ft_dir(t_game *game);
int			ft_size(t_game *game);

/* raycaster2_bonus.c */
int			ft_check_door(t_game *game, int precise_x, int precise_y, int flag);
void		ft_ver(t_game *game, t_player *player);
void		ft_hor(t_game *game, t_player *player);
void		ft_column(t_game *game, int size, int screen_x);

/* texturing.c */
int			find_texture_col(t_game *game);
int			find_texel(t_game *game, int count_pix, int wall_heigh, int coltex);
int			ft_get_texel_color(t_game *game, int x, int y);
int			ft_get_texel_color_bonus(t_game *game, int x, int y);

#endif