#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_map
{
	char **map;
	int height;
	int width;
	int collectibles;
	int player;
	int exitl;
	
} t_map;

char	*get_next_line(int fd);

#endif