#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		logex("Invalid number of arguments");
	game.map = (t_map *)malloc(sizeof(t_map));
	if (!game.map)
		logex("Memory allocation failed");
	read_map(game.map, argv[1]);
	check_map(game.map);
	check_path(game.map);
	init_graphics(&game);
	mlx_key_hook(game.display->wn, key_press, &game);
	mlx_hook(game.display->wn, 17, 0, game_off, &game);
	mlx_loop(game.display->mx);
	return (0);
}
