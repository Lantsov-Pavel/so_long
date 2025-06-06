#include "../includes/so_long.h"

static int	process_line(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = (int)ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		return (len - 1);
	}
	return (len);
}

static void	check_rect(t_map *map, int fd)
{
	char	*line;
	int		line_len;

	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = process_line(line);
		if (map->width == 0)
			map->width = line_len;
		else if (map->width != line_len)
		{
			free(line);
			close(fd);
			logex("Map is not rectangular");
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	allocate_map(t_map *map)
{
	int	i;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		logex("Memory allocation failed");
	i = 0;
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->map[i])
		{
			while (i-- > 0)
				free(map->map[i]);
			free(map->map);
			logex("Memory allocation failed");
		}
		i++;
	}
	map->map[map->height] = NULL;
}

static void	fill_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i >= map->height)
		{
			free(line);
			close(fd);
			logex("Map reading error");
		}	
		process_line(line);
		ft_strlcpy(map->map[i], line, map->width + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
}

void	read_map(t_map *map, char *path)
{
	int		fd;

	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		logex("Invalid file extension, must be .ber");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		logex("Cannot open map file");
	check_rect(map, fd);
	close(fd);
	if (map->height < 3 || map->width < 3)
		logex("Map is small");
	allocate_map(map);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		logex("Cannot open map file");
	fill_map(map, fd);
	close(fd);
}
