#include "../includes/so_long.h"

static char	**allocate_visited(int height, int width)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * height);
	if (!visited)
		logex("Memory allocation failed");
	i = 0;
	while (i < height)
	{
		visited[i] = (char *)ft_calloc(width, 1);
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			logex("Memory allocation failed");
		}
		i++;
	}
	return (visited);
}

static void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	fill_visit(t_map *map, char **visited, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->map[y][x] == '1' || visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	fill_visit(map, visited, x + 1, y);
	fill_visit(map, visited, x - 1, y);
	fill_visit(map, visited, x, y + 1);
	fill_visit(map, visited, x, y - 1);
}

static void	check_reach(t_map *map, char **visited, int *collects, int *exit)
{
	int	i;
	int	j;

	*exit = 0;
	*collects = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (visited[i][j])
			{
				if (map->map[i][j] == 'C')
					(*collects)++;
				else if (map->map[i][j] == 'E')
					*exit = 1;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_map *map)
{
	char	**visited;
	int		collects;
	int		is_exit_founded;

	visited = allocate_visited(map->height, map->width);
	fill_visit(map, visited, map->pos_pl_x, map->pos_pl_y);
	check_reach(map, visited, &collects, &is_exit_founded);
	free_visited(visited, map->height);
	if (collects != map->collects)
		logex("Some collectibles are not reachable");
	if (is_exit_founded != 1)
		logex("Exit is not reachable");
}
