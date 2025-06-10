#include "../includes/so_long.h"

static void	set_pos_player(t_map *map, int x, int y)
{
	map->plc++;
	map->pos_pl_x = x;
	map->pos_pl_y = y;
}

static void	set_pos_exit(t_map *map, int x, int y)
{
	map->exc++;
	map->pos_ex_x = x;
	map->pos_ex_y = y;
}

static void	set_values_and_check_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				set_pos_player(map, j, i);
			else if (map->map[i][j] == 'E')
				set_pos_exit(map, j, i);
			else if (map->map[i][j] == 'C')
				map->collects++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				logex("Map contains invalid elements");
			j++;
		}
		i++;
	}
}

static void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			logex("Map contains invalid walls");
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			logex("Map contains invalid walls");
		i++;
	}
}

void	check_map(t_map *map)
{
	map->collects = 0;
	map->exc = 0;
	map->plc = 0;
	set_values_and_check_elements(map);
	check_walls(map);
	if (map->plc != 1 || map->exc != 1)
		logex("Map must contain only 1 exit and 1 player");
	if (map->collects < 1)
    logex("Map must contain at least 1 collectible");
}
