#include "../includes/so_long.h"

static void	set_win(t_game *game, int size)
{
	t_display *dsp 

	dsp = game->display;
	size = 32;
	dsp->height = game->map->height * size;
	dsp->width = game->map->width * size;
	dsp->mlx = mlx_init();
	if (!dsp->mlx)
		logex("Initialization of mlx failed");
	dsp->win = mlx_new_window(dsp->mlx, dsp->width, dsp->height, "so_long");
	if (!dsp->win)
		logex("Creation of window failed");
}
static void	load_textures(t_game *game)
{
	t_display	*dsp 	
	int			w;
	int			h;

	dsp = game->display;
	dsp->txr_play = mlx_xpm_file_to_image(dsp->mlx, "textures/p.xpm", &w, &h);
	dsp->txr_exit = mlx_xpm_file_to_image(dsp->mlx, "textures/e.xpm", &w, &h);
	dsp->txr_coll = mlx_xpm_file_to_image(dsp->mlx, "textures/c.xpm", &w, &h);
	dsp->txr_wall = mlx_xpm_file_to_image(dsp->mlx, "textures/w.xpm", &w, &h);
	dsp->txr_grnd = mlx_xpm_file_to_image(dsp->mlx, "textures/g.xpm", &w, &h);
	if (!dsp->txr_play || !dsp->txr_exit || !dsp->txr_coll || !dsp->txr_wall || !dsp->txr_grnd)
		logex("Textures were not loaded");
}
void	draw_map(t_game *game, int s)
{
	t_display	*dsp;
	t_map		*map;
	int		i;
	int		j;
    	
	dsp = game->display;
	map = game->map;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->txr_gd, j * s, i * s);
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->txr_wl, j * s, i * s);
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->txr_pl, j * s, i * s);
			if (map->map[i][j] == 'E')
			       	mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->txr_ex, j * s, i * s);
			if (map->map[i][j] == 'C')
				mlx_put_image_to_window(dsp->mlx, dsp->win, dsp->txr_cl, j * s, i * s);

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
