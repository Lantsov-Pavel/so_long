#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysymdef.h>
# include <fcntl.h>
# define BUFFER_SIZE 42

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collects;
	int		pos_pl_x;
	int		pos_pl_y;
	int		pos_ex_x;
	int		pos_ex_y;
	int		plc;
	int		exc;

}	t_map;

typedef struct s_display
{
	void	*mx;
	void	*wn;
	int		height;
	int		width;
	void	*pl;
	void	*ex;
	void	*ct;
	void	*wl;
	void	*gd;
}	t_display;

typedef struct s_game
{
	t_display	*display;
	t_map		*map;
	int			moves;
	int			collects;
}	t_game;

char	*get_next_line(int fd);
void	read_map(t_map *map, char *path);
void	draw_map(t_game *game, int size);
void	check_map(t_map *map);
void	check_path(t_map *map);
void	logex(char *mes);
void	init_graphics(t_game *game);
int		key_press(int k_code, t_game *game);
int		game_off(t_game *game);

#endif
