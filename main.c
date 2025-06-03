#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
		logex("Invalid number of arguments");
	read_map(&map, argv[1]);
	check_map(&map);
	check_path(&map);
	ft_printf("Map validation successful!\n");
	int i = -1;
	while (++i < map.height)
		free(map.map[i]);
	free(map.map);

	return 0;
}
