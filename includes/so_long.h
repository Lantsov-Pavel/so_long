#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include "libft/libft.h"
# include <fcntl.h>
# define BUFFER_SIZE 42

typedef struct s_map
{
	char **map;
	int height;
	int width;
	int collects;
	int pos_pl_x;
	int pos_pl_y;
	int pos_ex_x;
	int pos_ex_y;
	int plc;
	int exc;

} t_map;

char	*get_next_line(int fd);
void	read_map(t_map *map, char *path);
void	check_map(t_map *map);
void	check_path(t_map *map);
void	logex(char *mes);


#endif