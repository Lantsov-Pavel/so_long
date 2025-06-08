#include "../includes/so_long.h"

static void	set_win(t_game *game, int size)
{
	t_display	*dsp;

	dsp = game->display;
	dsp->height = game->map->height * size;
	dsp->width = game->map->width * size;
	dsp->mx = mlx_init();
	if (!dsp->mx)
		logex("Initialization of mlx failed");
	dsp->wn = mlx_new_window(dsp->mx, dsp->width, dsp->height, "so_long");
	if (!dsp->wn)
		logex("Creation of window failed");
}

static void	load_textures(t_game *game)
{
	t_display	*dp;
	int			w;
	int			h;

	dp = game->display;
	dp->pl = mlx_xpm_file_to_image(dp->mx, "textures/p.xpm", &w, &h);
	dp->ex = mlx_xpm_file_to_image(dp->mx, "textures/e.xpm", &w, &h);
	dp->ct = mlx_xpm_file_to_image(dp->mx, "textures/c.xpm", &w, &h);
	dp->wl = mlx_xpm_file_to_image(dp->mx, "textures/w.xpm", &w, &h);
	dp->gd = mlx_xpm_file_to_image(dp->mx, "textures/g.xpm", &w, &h);
	if (!dp->pl || !dp->ex || !dp->ct || !dp->wl || !dp->gd)
		logex("Textures were not loaded");
}

void	draw_map(t_game *game, int s)
{
	t_display	*dp;
	int			i;
	int			j;

	dp = game->display;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(dp->mx, dp->wn, dp->gd, j * s, i * s);
			if (game->map->map[i][j] == '1')
				mlx_put_image_to_window(dp->mx, dp->wn, dp->wl, j * s, i * s);
			if (game->map->map[i][j] == 'P')
				mlx_put_image_to_window(dp->mx, dp->wn, dp->pl, j * s, i * s);
			if (game->map->map[i][j] == 'E')
				mlx_put_image_to_window(dp->mx, dp->wn, dp->ex, j * s, i * s);
			if (game->map->map[i][j] == 'C')
				mlx_put_image_to_window(dp->mx, dp->wn, dp->ct, j * s, i * s);
			j++;
		}
		i++;
	}
}

void	init_graphics(t_game *game)
{
	int	size;

	size = 32;
	game->display = malloc(sizeof(t_display));
	if (!game->display)
		logex("Memory allocation failed");
	set_win(game, size);
	load_textures(game);
	game->moves = 0;
	game->collects = 0;
	draw_map(game, size);
}
