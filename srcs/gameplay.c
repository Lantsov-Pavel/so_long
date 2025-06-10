#include "../includes/so_long.h"

int	game_off(t_game *game)
{
	int	i;

	if (game->display->wl)
		mlx_destroy_image(game->display->mx, game->display->wl);
	if (game->display->gd)
		mlx_destroy_image(game->display->mx, game->display->gd);
	if (game->display->pl)
		mlx_destroy_image(game->display->mx, game->display->pl);
	if (game->display->ct)
		mlx_destroy_image(game->display->mx, game->display->ct);
	if (game->display->ex)
		mlx_destroy_image(game->display->mx, game->display->ex);
	mlx_destroy_window(game->display->mx, game->display->wn);
	mlx_destroy_display(game->display->mx);
	i = 0;
	while (i < game->map->height)
		free(game->map->map[i++]);
	free(game->map->map);
	free(game->display);
	free(game->map);
	exit(0);
	return (0);
}

static void	refresh_pos_player(t_game *game, int next_x, int next_y)
{
	int	ex_y;
	int	ex_x;

	ex_y = game->map->pos_ex_y;
	ex_x = game->map->pos_ex_x;
	if ((game->map->pos_pl_y == ex_y) && (game->map->pos_pl_x == ex_x))
		game->map->map[game->map->pos_pl_y][game->map->pos_pl_x] = 'E';
	else
		game->map->map[game->map->pos_pl_y][game->map->pos_pl_x] = '0';
	game->map->pos_pl_x = next_x;
	game->map->pos_pl_y = next_y;
	game->map->map[next_y][next_x] = 'P';
	draw_map(game, 32);
}

static void	pl_move(t_game *game, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = game->map->pos_pl_x + x;
	next_y = game->map->pos_pl_y + y;
	if (game->map->map[next_y][next_x] == '1')
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map->map[next_y][next_x] == 'C')
		game->collects++;
	if (game->map->map[next_y][next_x] == 'E')
	{
		if (game->collects == game->map->collects)
		{
			ft_printf("You win! Total moves: %d\n", game->moves);
			game_off(game);
			return ;
		}
	}
	refresh_pos_player(game, next_x, next_y);
}

int	key_press(int k_code, t_game *game)
{
	if (k_code == 0x0097 || k_code == 0x0077)
		pl_move(game, 0, -1);
	else if (k_code == 0x0041 || k_code == 0x0061)
		pl_move(game, -1, 0);
	else if (k_code == 0x0053 || k_code == 0x0073)
		pl_move(game, 0, 1);
	else if (k_code == 0x0044 || k_code == 0x0064)
		pl_move(game, 1, 0);
	else if (k_code == 0xff1b)
		game_off(game);
	return (0);
}
